/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:47:32 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/09 18:26:27 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	first_process(t_pipex_obj *pipex_data, char *cmd,
	char *envp[], char *argv[])
{
	char	*cmd_path;
	char	**cmd_args;
	pid_t	pid;
	int		infile_d;

	infile_d = open(argv[1], O_RDONLY);
	if (infile_d < 0)
		return (perror("pipex: input"), close(pipex_data->pipes[0 + 1]), 1);
	pid = fork();
	if (pid == 0)
	{
		cmd_args = ft_split(cmd, ' ');
		cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
		if (cmd_path == NULL)
			return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
				write(2, ": command not found\n", 20), exit(127), 127);
		dup2(infile_d, STDIN_FILENO);
		dup2(pipex_data->pipes[0 + 1], STDOUT_FILENO);
		close(pipex_data->pipes[0 + 0]);
		if (execve(cmd_path, cmd_args, envp) == -1)
			return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
				split_clear(cmd_args), free(cmd_path),
				perror("command failed:"), exit(126), 126);
		split_clear(cmd_args);
		free(cmd_path);
		exit(0);
	}
	close(infile_d);
	close(pipex_data->pipes[0 + 1]);
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
		cmd_args = ft_split(cmd, ' ');
		cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
		if (cmd_path == NULL)
			return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
				write(2, ": command not found\n", 20), exit(127), 127);
		dup2(pipex_data->pipes[arr_cursor - 2 + 0], STDIN_FILENO);
		close(pipex_data->pipes[arr_cursor - 2 + 1]);
		dup2(pipex_data->pipes[arr_cursor + 1], STDOUT_FILENO);
		close(pipex_data->pipes[arr_cursor + 0]);
		if (execve(cmd_path, cmd_args, envp) == -1)
			return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
				split_clear(cmd_args), free(cmd_path),
				perror("command failed:"), exit(126), 126);
		split_clear(cmd_args);
		free(cmd_path);
		exit(0);
	}
	close(pipex_data->pipes[arr_cursor - 2 + 0]);
	close(pipex_data->pipes[arr_cursor + 1]);
	return (0);
}

static int	last_process(t_pipex_obj *pipex_data, char *cmd,
	char *envp[], int arr_cursor, char *argv[])
{
	char	*cmd_path;
	char	**cmd_args;
	int		outfile_d;
	pid_t	pid;
	int		status;

	outfile_d = open(argv[pipex_data->ac - 1], O_TRUNC | O_CREAT
			| O_RDWR, 0000644);
	if (outfile_d < 0)
		return (perror("pipex: output:"), 1);
	pid = fork();
	if (pid == 0)
	{
		cmd_args = ft_split(cmd, ' ');
		cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
		if (cmd_path == NULL)
			return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
				write(2, ": command not found\n", 20), exit(127), 127);
		dup2(outfile_d, STDOUT_FILENO);
		dup2(pipex_data->pipes[arr_cursor - 2 + 0], STDIN_FILENO);
		close(pipex_data->pipes[arr_cursor - 2 + 1]);
		if (execve(cmd_path, cmd_args, envp) == -1)
			return (split_clear(cmd_args), free(cmd_path),
				perror("command failed:"), exit(126), 126);
		split_clear(cmd_args);
		free(cmd_path);
		exit(0);
	}
	close(outfile_d);
	close(pipex_data->pipes[arr_cursor - 2 + 0]);
	waitpid(-1, &status, 0);
	return (WEXITSTATUS(status));
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
	pipex_data->ac = ac;
	return (0);
}

int	main(int ac, char *argv[], char *envp[])
{
	t_pipex_obj	pipex_data;
	int			i;
	int			status;

	if (init(&pipex_data, ac, envp) == -1)
		return (1);
	first_process(&pipex_data, argv[2], envp, argv);
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
			envp, i * 2, argv);
	cleanup_all(&pipex_data, i * 2);
	exit(status);
}
