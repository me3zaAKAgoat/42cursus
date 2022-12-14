/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:27:05 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/10 21:45:06 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fp_core(t_pipex_obj *pipex_data, char *cmd, int infile_d)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
	printf("%s %s %s\n", cmd_args[0], cmd_args[1], cmd_args[2]);
	if (cmd_path == NULL)
		return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
			write(2, ": command not found\n", 20),
			exit(ERR_NOTFOUND), ERR_NOTFOUND);
	dup2(infile_d, STDIN_FILENO);
	dup2(pipex_data->pipes[0 + 1], STDOUT_FILENO);
	close(pipex_data->pipes[0 + 0]);
	if (execve(cmd_path, cmd_args, pipex_data->envp) == -1)
		return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
			split_clear(cmd_args), free(cmd_path),
			perror("command failed:"), exit(ERR_EXEC), ERR_EXEC);
	split_clear(cmd_args);
	free(cmd_path);
	exit(0);
}

int	mp_core(t_pipex_obj *pipex_data, char *cmd, int arr_cursor)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
	if (cmd_path == NULL)
		return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
			write(2, ": command not found\n", 20),
			exit(ERR_NOTFOUND), ERR_NOTFOUND);
	dup2(pipex_data->pipes[arr_cursor - 2 + 0], STDIN_FILENO);
	close(pipex_data->pipes[arr_cursor - 2 + 1]);
	dup2(pipex_data->pipes[arr_cursor + 1], STDOUT_FILENO);
	close(pipex_data->pipes[arr_cursor + 0]);
	if (execve(cmd_path, cmd_args, pipex_data->envp) == -1)
		return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
			split_clear(cmd_args), free(cmd_path),
			perror("command failed:"), exit(ERR_EXEC), ERR_EXEC);
	split_clear(cmd_args);
	free(cmd_path);
	exit(0);
}

int	lp_core(t_pipex_obj *pipex_data, char *cmd,
	int arr_cursor, int outfile_d)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
	if (cmd_path == NULL)
		return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
			write(2, ": command not found\n", 20),
			exit(ERR_NOTFOUND), ERR_NOTFOUND);
	dup2(outfile_d, STDOUT_FILENO);
	dup2(pipex_data->pipes[arr_cursor - 2 + 0], STDIN_FILENO);
	close(pipex_data->pipes[arr_cursor - 2 + 1]);
	if (execve(cmd_path, cmd_args, pipex_data->envp) == -1)
		return (split_clear(cmd_args), free(cmd_path),
			perror("command failed:"), exit(ERR_EXEC), ERR_EXEC);
	split_clear(cmd_args);
	free(cmd_path);
	exit(0);
}
