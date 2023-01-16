/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:27:05 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/16 20:05:14 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fp_core(t_pipex_obj *pipex_data, char *cmd, int infile_d)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
	if (cmd_path == NULL)
		return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
			write(2, ": command not found\n", 20),
			exit(ERR_NOTFOUND));
	close(pipex_data->pipes[0 + 0]);
	dup2(infile_d, STDIN_FILENO);
	dup2(pipex_data->pipes[0 + 1], STDOUT_FILENO);
	close(infile_d);
	close(pipex_data->pipes[0 + 1]);
	if (execve(cmd_path, cmd_args, pipex_data->envp) == -1)
		return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
			split_clear(cmd_args), free(cmd_path),
			perror("command failed:"), exit(ERR_EXEC));
}

void	mp_core(t_pipex_obj *pipex_data, char *cmd, int arr_cursor)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
	if (cmd_path == NULL)
		return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
			write(2, ": command not found\n", 20),
			exit(ERR_NOTFOUND));
	close(pipex_data->pipes[arr_cursor + 0]);
	dup2(pipex_data->pipes[arr_cursor - 2 + 0], STDIN_FILENO);
	dup2(pipex_data->pipes[arr_cursor + 1], STDOUT_FILENO);
	close(pipex_data->pipes[arr_cursor - 2 + 0]);
	close(pipex_data->pipes[arr_cursor + 1]);
	if (execve(cmd_path, cmd_args, pipex_data->envp) == -1)
		return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
			split_clear(cmd_args), free(cmd_path),
			perror("command failed:"), exit(ERR_EXEC));
}

void	lp_core(t_pipex_obj *pipex_data, char *cmd,
	int arr_cursor, int outfile_d)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd(pipex_data->program_paths, cmd_args[0]);
	if (cmd_path == NULL)
		return (write(2, cmd_args[0], ft_strlen(cmd_args[0])),
			write(2, ": command not found\n", 20), split_clear(cmd_args),
			exit(ERR_NOTFOUND));
	dup2(outfile_d, STDOUT_FILENO);
	dup2(pipex_data->pipes[arr_cursor + 0], STDIN_FILENO);
	close(outfile_d);
	close(pipex_data->pipes[arr_cursor + 0]);
	if (execve(cmd_path, cmd_args, pipex_data->envp) == -1)
		return (split_clear(cmd_args), free(cmd_path),
			perror("command failed:"), exit(ERR_EXEC));
}
