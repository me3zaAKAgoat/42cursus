/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:47:32 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/14 01:51:31 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	fp_wrapper(t_pipex_obj *pipex_data, char *cmd)
{
	pid_t	pid;
	int		infile_d;

	infile_d = open(pipex_data->argv[1], O_RDONLY);
	if (infile_d < 0)
	{
		perror("pipex: input");
		close(pipex_data->pipes[0 + 1]);
	}
	pid = fork();
	if (pid == 0)
		fp_core(pipex_data, cmd, infile_d);
	else
		close(infile_d);
}

static void	mp_wrapper(t_pipex_obj *pipex_data, char *cmd, int arr_cursor)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		mp_core(pipex_data, cmd, arr_cursor);
}

static void	lp_wrapper(t_pipex_obj *pipex_data, char *cmd, int arr_cursor)
{
	int		outfile_d;
	pid_t	pid;

	outfile_d = open(pipex_data->argv[pipex_data->ac - 1], O_TRUNC | O_CREAT
			| O_RDWR, 0000644);
	if (outfile_d < 0)
		perror("pipex: output:");
	pid = fork();
	if (pid == 0)
		lp_core(pipex_data, cmd, arr_cursor, outfile_d);
	else
		close(outfile_d);
}

static int	init(t_pipex_obj *pipex_data, int ac, char *envp[], char *argv[])
{
	int		*alloc_pipes;
	int		pipe_number;

	if (ac < 5)
		return (-1);
	pipex_data->program_paths = get_paths(envp);
	if (pipex_data->program_paths == NULL)
		return (perror("program paths not found"), -1);
	alloc_pipes = malloc(sizeof(int) * 2 * (ac - 4));
	if (alloc_pipes == NULL)
		return (perror("allocation for pipes failed"), -1);
	pipex_data->pipes = alloc_pipes;
	pipe_number = 0;
	while (pipe_number < ac - 4)
	{
		if (pipe(pipex_data->pipes + pipe_number * 2) < 0)
			return (cleanup_all(pipex_data, 0),
				perror("making pipes failed"), -1);
		pipe_number++;
	}	
	return (pipex_data->ac = ac, pipex_data->envp = envp,
			pipex_data->argv = argv, 0);
}

int	main(int ac, char *argv[], char *envp[])
{
	t_pipex_obj	pipex_data;
	int			command_nbr;
	int			status;

	if (init(&pipex_data, ac, envp, argv) == -1)
		exit(1);
	fp_wrapper(&pipex_data, argv[2]);
	command_nbr = 1;
	while (command_nbr < ac - 4)
	{
		mp_wrapper(&pipex_data, argv[command_nbr + 2], command_nbr * 2);
		command_nbr++;
	}
	lp_wrapper(&pipex_data, argv[(ac - 1) - 1], command_nbr * 2 - 2);
	cleanup_all(&pipex_data, command_nbr * 2);
	wait(&status);
	exit(WEXITSTATUS(status));
}
