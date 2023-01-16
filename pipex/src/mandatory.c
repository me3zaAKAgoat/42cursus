/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:47:32 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/16 19:13:08 by echoukri         ###   ########.fr       */
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
		return ;
	}
	pid = fork();
	if (pid == 0)
		fp_core(pipex_data, cmd, infile_d);
	else
	{
		close(infile_d);
		close(pipex_data->pipes[0 + 1]);
	}
}

static void	lp_wrapper(t_pipex_obj *pipex_data, char *cmd)
{
	int		outfile_d;
	pid_t	pid;

	outfile_d = open(pipex_data->argv[pipex_data->ac - 1], O_TRUNC | O_CREAT
			| O_RDWR, 0000644);
	if (outfile_d < 0)
	{
		perror("pipex: output:");
		close(pipex_data->pipes[0 + 0]);
		return ;
	}
	pid = fork();
	if (pid == 0)
		lp_core(pipex_data, cmd, 0, outfile_d);
	else
	{
		close(outfile_d);
		close(pipex_data->pipes[0 + 0]);
	}
}

static int	init(t_pipex_obj *pipex_data, int ac, char *envp[], char *argv[])
{
	int		*alloc_pipes;

	if (ac != 5)
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
	int			status;

	if (init(&pipex_data, ac, envp, argv) == -1)
		return (perror("wrong number of arguments"), exit(1), 1);
	fp_wrapper(&pipex_data, argv[2]);
	lp_wrapper(&pipex_data, argv[(ac - 1) - 1]);
	cleanup_all(&pipex_data, 2);
	wait(&status);
	exit(WEXITSTATUS(status));
}
