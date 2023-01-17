/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:47:32 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/17 21:56:38 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_child(t_pipex_obj *pipex_data, char *cmd)
{
	int		infile_d;
	pid_t	pid;

	if (pipex_data->heredoc_offset > 0)
		infile_d = open(".tmp.txt", O_RDONLY);
	else
		infile_d = open(pipex_data->argv[1], O_RDONLY);
	if (infile_d < 0)
		return (close(pipex_data->pipes[0 + 1]), perror("pipex: input"));
	pid = fork();
	if (pid == 0)
		first_child_core(pipex_data, cmd, infile_d);
	else if (pid < 0)
		return (perror("fork failed:"), exit(1));
	else
	{
		close(infile_d);
		close(pipex_data->pipes[0 + 1]);
	}
}

static void	middle_child(t_pipex_obj *pipex_data, char *cmd, int arr_cursor)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		middle_child_core(pipex_data, cmd, arr_cursor);
	else if (pid < 0)
		return (perror("fork failed:"), exit(1));
	else
	{
		close(pipex_data->pipes[arr_cursor - 2 + 0]);
		close(pipex_data->pipes[arr_cursor + 1]);
	}
}

static void	last_child(t_pipex_obj *pipex_data, char *cmd, int arr_cursor)
{
	int		outfile_d;
	pid_t	pid;

	if (pipex_data->heredoc_offset > 0)
		outfile_d = open(pipex_data->argv[pipex_data->ac - 1], O_CREAT
				| O_RDWR | O_APPEND, 0000644);
	else
		outfile_d = open(pipex_data->argv[pipex_data->ac - 1], O_TRUNC | O_CREAT
				| O_RDWR, 0000644);
	if (outfile_d < 0)
		return (perror("pipex: output:"));
	pid = fork();
	if (pid == 0)
		last_child_core(pipex_data, cmd, arr_cursor, outfile_d);
	else if (pid < 0)
		return (perror("fork failed:"), exit(1));
	else
	{
		close(outfile_d);
		close(pipex_data->pipes[arr_cursor + 0]);
		if (pipex_data->heredoc_offset > 0)
			unlink(".tmp.txt");
	}
}

static int	init(t_pipex_obj *pipex_data, int ac, char *envp[], char *argv[])
{
	int		pipe_number;

	if (ac - pipex_data->heredoc_offset < 5)
		return (perror("wrong number of arguments"), -1);
	pipex_data->program_paths = get_paths(envp);
	if (pipex_data->program_paths == NULL)
		return (perror("program paths not found"), -1);
	pipex_data->pipes = malloc(sizeof(int) * 2
			* (ac - pipex_data->heredoc_offset - 4));
	if (pipex_data->pipes == NULL)
		return (perror("allocation for pipes failed"), -1);
	pipe_number = 0;
	while (pipe_number < ac - pipex_data->heredoc_offset - 4)
	{
		if (pipe(pipex_data->pipes + pipe_number * 2) < 0)
			return (cleanup_all(pipex_data, 0),
				perror("making pipes failed"), -1);
		pipe_number++;
	}	
	return (pipex_data->ac = ac, pipex_data->envp = envp,
		pipex_data->argv = argv, 0);
}

/*
the heredoc_offset plays the role of an indicator to wether the bonus
is ran with a here doc or just an infile, and also the role of setting
the offset of all argv array indexes to 1 indexes further to the right
*/
int	main(int ac, char *argv[], char *envp[])
{
	t_pipex_obj	pipex_data;
	int			command_nbr;
	int			status;

	setup_heredoc(&pipex_data, argv);
	if (init(&pipex_data, ac, envp, argv) == -1)
		exit(1);
	first_child(&pipex_data, argv[pipex_data.heredoc_offset + 2]);
	command_nbr = 1;
	while (command_nbr < ac - pipex_data.heredoc_offset - 4)
	{
		middle_child(&pipex_data,
			argv[pipex_data.heredoc_offset + 2 + command_nbr], command_nbr * 2);
		command_nbr++;
	}
	last_child(&pipex_data, argv[(ac - 1) - 1],
		command_nbr * 2 - 2);
	cleanup_all(&pipex_data, command_nbr * 2);
	wait(&status);
	exit(WEXITSTATUS(status));
}
