/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:47:32 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/05 19:13:19 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*

create a long ass fuckign array*/

void	first_process(t_pipex_obj *pipex_data, char *cmd,
	char *envp[], int arr_cursor)
{
	char	*cmd_path;
	char	**cmd_args;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(pipex_data->infile_d, STDIN_FILENO);
		dup2(pipex_data->pipes[arr_cursor + 1], STDOUT_FILENO);
		close(pipex_data->pipes[arr_cursor + 0]);
		cmd_args = ft_split(cmd, ' ');
		cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
		execve(cmd_path, cmd_args, envp);
		split_clear(cmd_args);
		free(cmd_path);
		exit(0);
	}
}

void	mid_process(t_pipex_obj *pipex_data, char *cmd,
	char *envp[], int arr_cursor)
{
	char	*cmd_path;
	char	**cmd_args;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(pipex_data->pipes[arr_cursor - 2 + 0], STDIN_FILENO);
		close(pipex_data->pipes[arr_cursor - 2 + 1]);
		dup2(pipex_data->pipes[arr_cursor + 1], STDOUT_FILENO);
		close(pipex_data->pipes[arr_cursor + 0]);
		cmd_args = ft_split(cmd, ' ');
		cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
		execve(cmd_path, cmd_args, envp);
		split_clear(cmd_args);
		free(cmd_path);
		exit(0);
	}
}

void	last_process(t_pipex_obj *pipex_data, char *cmd,
	char *envp[], int arr_cursor)
{
	char	*cmd_path;
	char	**cmd_args;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(pipex_data->outfile_d, STDOUT_FILENO);
		dup2(pipex_data->pipes[arr_cursor - 2 + 0], STDIN_FILENO);
		close(pipex_data->pipes[arr_cursor - 2 + 1]);
		cmd_args = ft_split(cmd, ' ');
		cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
		execve(cmd_path, cmd_args, envp);
		split_clear(cmd_args);
		free(cmd_path);
		exit(0);
	}
}

int	init(t_pipex_obj *pipex_data, int ac, char *argv[], char *envp[])
{
	int		*alloc_pipes;

	pipex_data->program_paths = get_paths(envp);
	if (pipex_data->program_paths == NULL)
		return (-1);
	pipex_data->infile_d = open(argv[1], O_RDONLY);
	pipex_data->outfile_d = open(argv[ac - 1], O_TRUNC | O_CREAT | O_RDWR);
	if (pipex_data->infile_d == -1 || pipex_data->outfile_d == -1)
		return (clear_pipex_data(pipex_data, ac), -1);
	alloc_pipes = malloc(sizeof(int) * 2 * (ac - 4));
	if (alloc_pipes == NULL)
		return (clear_pipex_data(pipex_data, ac), -1);
	pipex_data->pipes = alloc_pipes;
	if (pipe(pipex_data->pipes) == -1)
		return (clear_pipex_data(pipex_data, ac), -1);
	first_process(pipex_data, argv[2], envp, 0);
	return (0);
}

int	main(int ac, char *argv[], char *envp[])
{
	t_pipex_obj	pipex_data;
	int			i;

	if (init(&pipex_data, ac, argv, envp) == -1)
		return (-1);
	i = 1;
	while (i < ac - 4)
	{
		if (pipe(pipex_data.pipes + i + 1) == -1)
			return (clear_pipex_data(&pipex_data, ac), -1);
		mid_process(&pipex_data, argv[i + 2], envp, i * 2);
		i++;
	}
	last_process(&pipex_data, argv[ac - 2], envp, i * 2);
	clear_pipex_data(&pipex_data, ac);
	return (0);
}
