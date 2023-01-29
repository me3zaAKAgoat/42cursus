/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:47:32 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/29 21:42:11 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_child(t_pipex_obj *pipex_data, char *cmd)
{
	int		infile_d;
	pid_t	pid;

	infile_d = open(pipex_data->argv[1], O_RDONLY);
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
	}
}

static void	last_child(t_pipex_obj *pipex_data, char *cmd)
{
	int		outfile_d;
	pid_t	pid;

	outfile_d = open(pipex_data->argv[pipex_data->ac - 1], O_TRUNC | O_CREAT
			| O_RDWR, 0000644);
	if (outfile_d < 0)
		return (close(pipex_data->pipes[0 + 0]), perror("pipex: output:"));
	pid = fork();
	if (pid == 0)
		last_child_core(pipex_data, cmd, 0, outfile_d);
	else if (pid < 0)
		perr_exit("fork failed:");
	else
	{
		close(outfile_d);
		close(pipex_data->pipes[0 + 0]);
	}
}

static void	init_struct(t_pipex_obj *pipex_data,
			int ac, char *envp[], char *argv[])
{
	pipex_data->ac = ac;
	pipex_data->envp = envp;
	pipex_data->argv = argv;
	pipex_data->program_paths = get_pathenv(envp);
	if (pipex_data->program_paths == NULL)
		perr_exit("program paths not found");
	pipex_data->pipes = malloc(sizeof(int) * 2 * (ac - ARGC_PIPE_OFFSET));
	if (pipex_data->pipes == NULL)
		return (split_clear(pipex_data->program_paths),
			perr_exit("allocation for pipes failed"));
	if (pipe(pipex_data->pipes) == -1)
		return (free_struct(pipex_data), perr_exit("first pipe failed"));
}

int	main(int ac, char *argv[], char *envp[])
{
	t_pipex_obj	pipex_data;
	int			status;

	if (ac != MINIMUM_ARGC)
		perr_exit("wrong number of arguments");
	init_struct(&pipex_data, ac, envp, argv);
	first_child(&pipex_data, argv[2]);
	last_child(&pipex_data, argv[(ac - 1) - 1]);
	free_struct(&pipex_data);
	wait(&status);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else
		perr_exit("fatal signal error");
}
