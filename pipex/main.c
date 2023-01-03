/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:47:32 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/03 17:02:28 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
create a loop based on the argument count
on each iteration of the loop creates a pipe

start pipe and end pipe should be handled sperately from the loop
*/

void	first_process(t_pipex_obj *pipex_data,	char *cmd, char *envp[])
{
	char	*cmd_path;
	char	**cmd_args;

	dup2(pipex_data->infile_d, STDIN_FILENO);
	dup2(pipex_data->pipe[1], STDOUT_FILENO);
	close(pipex_data->pipe[0]);
	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
	execve(cmd_path, cmd_args, envp);
	split_clear(cmd_args);
	free(cmd_path);
	exit(0);
}

void	mid_process(t_pipex_obj *pipex_data,	char *cmd, char *envp[])
{
	char	*cmd_path;
	char	**cmd_args;

	dup2(pipex_data->pipe[0], STDIN_FILENO);
	dup2(pipex_data->pipe[1], STDOUT_FILENO);
	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
	execve(cmd_path, cmd_args, envp);
	split_clear(cmd_args);
	free(cmd_path);
	exit(0);
}

void	last_process(t_pipex_obj *pipex_data,	char *cmd, char *envp[])
{
	char	*cmd_path;
	char	**cmd_args;

	dup2(pipex_data->outfile_d, STDOUT_FILENO);
	dup2(pipex_data->pipe[0], STDIN_FILENO);
	close(pipex_data->pipe[1]);
	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
	execve(cmd_path, cmd_args, envp);
	split_clear(cmd_args);
	free(cmd_path);
	exit(0);
}

int	init(t_pipex_obj *pipex_data, char *argv[], char *envp[])
{
	pipex_data->program_paths = get_paths(envp);
	if (pipex_data->program_paths == NULL)
		return (-1);
	pipex_data->infile_d = open(argv[1], O_RDONLY);
	pipex_data->outfile_d = open(argv[4], O_TRUNC | O_CREAT | O_RDWR);
	if (pipex_data->infile_d == -1 || pipex_data->outfile_d == -1)
		return (clear_pipex_data(pipex_data), -1);
	if (pipe(pipex_data->interloop_pipe) == -1)
		return (clear_pipex_data(pipex_data), -1);
	return (0);
}

int	main(int ac, char *argv[], char *envp[])
{
	t_pipex_obj	pipex_data;
	pid_t		pid1;
	pid_t		pid2;

	if (!ac)
		return (-1);
	if (init(&pipex_data, argv, envp) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 == 0)
		first_process(&pipex_data, argv[2], envp);
	pid2 = fork();
	if (pid2 == 0)
		last_process(&pipex_data, argv[3], envp);
	waitpid(pid1, NULL, WNOHANG);
	waitpid(pid2, NULL, WNOHANG);
	clear_pipex_data(&pipex_data);
	return (0);
}
