/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:47:32 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/29 21:42:02 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
if heredoc offset > 0
means we should open the tmp file that the heredoc provides in the working
directory
else
open the infile.
*/
static void	first_child(t_pipex_obj *pipex_data, char *cmd)
{
	int		infile_d;
	pid_t	pid;

	infile_d = open_in(pipex_data);
	if (infile_d < 0)
		return (close(pipex_data->pipes[0 + 1]), perror("pipex: input"));
	pid = fork();
	if (pid == 0)
		first_child_core(pipex_data, cmd, infile_d);
	else if (pid < 0)
		perr_exit("fork failed:");
	else
	{
		close(infile_d);
		close(pipex_data->pipes[0 + 1]);
		if (pipex_data->heredoc_offset > 0)
			unlink(".tmp.txt");
	}
}

static void	middle_child(t_pipex_obj *pipex_data, char *cmd, int arr_cursor)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		middle_child_core(pipex_data, cmd, arr_cursor);
	else if (pid < 0)
		perr_exit("fork failed:");
	else
	{
		close(pipex_data->pipes[arr_cursor - 2 + 0]);
		close(pipex_data->pipes[arr_cursor + 1]);
	}
}

/*
if heredoc offset > 0
means we should open outfile in append mode
else
open outfile in normal mode
*/
static void	last_child(t_pipex_obj *pipex_data, char *cmd, int arr_cursor)
{
	int		outfile_d;
	pid_t	pid;

	outfile_d = open_out(pipex_data);
	if (outfile_d < 0)
		return (perror("pipex: output:"));
	pid = fork();
	if (pid == 0)
		last_child_core(pipex_data, cmd, arr_cursor, outfile_d);
	else if (pid < 0)
		perr_exit("fork failed:");
	else
	{
		close(outfile_d);
		close(pipex_data->pipes[arr_cursor + 0]);
	}
}

static void	init_struct(t_pipex_obj *pipex_data,
			int ac, char *envp[], char *argv[])
{
	int		pipe_number;

	pipex_data->program_paths = get_pathenv(envp);
	if (pipex_data->program_paths == NULL)
		perr_exit("program paths not found");
	pipex_data->pipes = malloc(sizeof(int) * 2
			* (ac - pipex_data->heredoc_offset - ARGC_PIPE_OFFSET));
	if (pipex_data->pipes == NULL)
		return (split_clear(pipex_data->program_paths),
			perr_exit("allocation for pipes failed"));
	pipe_number = 0;
	while (pipe_number < ac - pipex_data->heredoc_offset - ARGC_PIPE_OFFSET)
	{
		if (pipe(pipex_data->pipes + pipe_number * 2) < 0)
			return (free_struct(pipex_data),
				perr_exit("making pipes failed"));
		pipe_number++;
	}	
	pipex_data->ac = ac;
	pipex_data->envp = envp;
	pipex_data->argv = argv;
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

	if (ac < MINIMUM_ARGC)
		perr_exit("wrong number of arguments");
	setup_heredoc(&pipex_data, argv, ac);
	init_struct(&pipex_data, ac, envp, argv);
	first_child(&pipex_data, argv[pipex_data.heredoc_offset + 2]);
	command_nbr = 1;
	while (command_nbr < ac - pipex_data.heredoc_offset - ARGC_PIPE_OFFSET)
	{
		middle_child(&pipex_data,
			argv[pipex_data.heredoc_offset + 2 + command_nbr], command_nbr * 2);
		command_nbr++;
	}
	last_child(&pipex_data, argv[(ac - 1) - 1], command_nbr * 2 - 2);
	free_struct(&pipex_data);
	wait(&status);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else
		perr_exit("fatal signal error");
}
