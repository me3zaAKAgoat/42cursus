/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:47:32 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/06 17:31:01 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	first_process(t_pipex_obj *pipex_data, char *cmd,
	char *envp[], int arr_cursor, char *argv[])
{
	char	*cmd_path;
	char	**cmd_args;
	pid_t	pid;
	int		infile_d;

	infile_d = open(argv[1], O_RDONLY);
	if (infile_d < 0)
		return (perror("pipex: input"), 0);
	pid = fork();
	if (pid == 0)
	{
		dup2(infile_d, STDIN_FILENO);
		dup2(pipex_data->pipes[arr_cursor + 1], STDOUT_FILENO);
		close(pipex_data->pipes[arr_cursor + 0]);
		cmd_args = ft_split(cmd, ' ');
		cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
		if (cmd_path == NULL)
			return (127);
		if (execve(cmd_path, cmd_args, envp) == -1)
			return (-1);
		split_clear(cmd_args);
		free(cmd_path);
		close(pipex_data->pipes[arr_cursor + 1]);
		close(infile_d);
	}
	return (0);
}

static int	mid_process(t_pipex_obj *pipex_data, char *cmd,
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
		if (cmd_path == NULL)
			return (127);
		if (execve(cmd_path, cmd_args, envp) == -1)
			return (-1);
		split_clear(cmd_args);
		free(cmd_path);
		close(pipex_data->pipes[arr_cursor - 2 + 0]);
		close(pipex_data->pipes[arr_cursor + 1]);
	}
	return (0);
}

static int	last_process(t_pipex_obj *pipex_data, char *cmd,
	char *envp[], int arr_cursor, char *argv[], int ac)
{
	char	*cmd_path;
	char	**cmd_args;
	int		outfile_d;
	pid_t	pid;

	outfile_d = open(argv[ac - 1], O_TRUNC | O_CREAT
			| O_RDWR, 0000644);
	if (outfile_d < 0)
		return (perror(""), 1);
	pid = fork();
	if (pid == 0)
	{
		dup2(outfile_d, STDOUT_FILENO);
		dup2(pipex_data->pipes[arr_cursor - 2 + 0], STDIN_FILENO);
		close(pipex_data->pipes[arr_cursor - 2 + 1]);
		cmd_args = ft_split(cmd, ' ');
		cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
		if (cmd_path == NULL)
			return (127);
		if (execve(cmd_path, cmd_args, envp) == -1)
			return (-1);
		split_clear(cmd_args);
		free(cmd_path);
		close(pipex_data->pipes[arr_cursor - 2 + 0]);
		close(outfile_d);
	}
	return (0);
}

static int	init(t_pipex_obj *pipex_data, int ac, char *envp[])
{
	int		*alloc_pipes;

	if (ac < 5)
		return (-1);
	pipex_data->program_paths = get_paths(envp);
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
	int			i;
	int			status;

	if (init(&pipex_data, ac, envp) == -1)
		return (1);
	first_process(&pipex_data, argv[2], envp, 0, argv);
	i = 1;
	while (i < ac - 4)
	{
		if (pipe(pipex_data.pipes + i * 2) == -1)
			return (cleanup_all(&pipex_data, i * 2),
				perror("middle pipe failed"), 1);
		mid_process(&pipex_data, argv[i + 2], envp, i * 2);
		i++;
	}
	status = last_process(&pipex_data, argv[(ac - 1) - 1],
			envp, i * 2, argv, ac);
	return (cleanup_all(&pipex_data, i * 2), status);
}
