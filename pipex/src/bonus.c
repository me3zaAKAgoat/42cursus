/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:47:32 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/11 16:43:00 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	fp_wrapper(t_pipex_obj *pipex_data, char *cmd)
{
	pid_t	pid;
	int		infile_d;

	infile_d = open(pipex_data->argv[1], O_RDONLY);
	if (infile_d < 0)
		return (perror("pipex: input"), close(pipex_data->pipes[0 + 1]), 1);
	pid = fork();
	if (pid == 0)
		fp_core(pipex_data, cmd, infile_d);
	close(infile_d);
	waitpid(pid, 0, WNOHANG);
	return (0);
}

static int	mp_wrapper(t_pipex_obj *pipex_data, char *cmd, int arr_cursor)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		mp_core(pipex_data, cmd, arr_cursor);
	waitpid(pid, 0, WNOHANG);
	return (0);
}

static int	lp_wrapper(t_pipex_obj *pipex_data, char *cmd, int arr_cursor)
{
	int		outfile_d;
	pid_t	pid;
	int		status;

	outfile_d = open(pipex_data->argv[pipex_data->ac - 1], O_TRUNC | O_CREAT
			| O_RDWR, 0000644);
	if (outfile_d < 0)
		return (perror("pipex: output:"), 1);
	pid = fork();
	if (pid == 0)
		lp_core(pipex_data, cmd, arr_cursor, outfile_d);
	close(outfile_d);
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

static int	init(t_pipex_obj *pipex_data, int ac, char *envp[], char *argv[])
{
	int		*alloc_pipes;

	if (ac < 5)
		return (-1);
	pipex_data->program_paths = get_paths(envp);
	pipex_data->ac = ac;
	pipex_data->envp = envp;
	pipex_data->argv = argv;
	if (pipex_data->program_paths == NULL)
		return (perror("program paths not found"), -1);
	alloc_pipes = malloc(sizeof(int) * 2 * (ac - 4));
	if (alloc_pipes == NULL)
		return (perror("allocation for pipes failed"),
			split_clear(pipex_data->program_paths), -1);
	pipex_data->pipes = alloc_pipes;
	if (pipe(pipex_data->pipes) == -1)
		return (cleanup_all(pipex_data, 0), perror("first pipe failed"), -1);
	return (0);
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
		if (pipe(pipex_data.pipes + command_nbr * 2) == -1)
			return (cleanup_all(&pipex_data, command_nbr * 2),
				perror("middle pipe failed"), 1);
		mp_wrapper(&pipex_data, argv[command_nbr + 2], command_nbr * 2);
		command_nbr++;
	}
	status = lp_wrapper(&pipex_data, argv[(ac - 1) - 1], command_nbr * 2 - 2);
	cleanup_all(&pipex_data, command_nbr * 2);
	exit(status);
}
