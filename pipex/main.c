/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:47:32 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/03 14:23:46 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// switch STDIN with vpipe[0] then execute 
// check dup2 failure
// tmp is base command and args wrapping array
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

void	second_process(t_pipex_obj *pipex_data,	char *cmd, char *envp[])
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

/*
make a structure that holds data that passes through all 
functions to facilitate handling freeing and closing of unused items
	structure must contain 
		{
			infile descritpor
			outfile descriptor
			pipe
		}
main function has to include these responsabilities
open the file descriptors for the infile and outfile
	check the case of error on file descritpor opening
make a pipe
	handle the error on pipe making
fork the processes for each command
	pass the structure
	handle errors on command
within proccesses
	handle freeing of memory used by susbsr, strjoin and split 

*/
int	main(int ac, char *argv[], char *envp[])
{
	t_pipex_obj	pipex_data;
	pid_t		pid1;
	pid_t		pid2;

	pipex_data.program_paths = get_paths(envp);
	if (pipex_data.program_paths == NULL)
		return (-1);
	pipex_data.infile_d = open(argv[1], O_RDONLY);
	pipex_data.outfile_d = open(argv[4], O_TRUNC | O_CREAT | O_RDWR);
	if (pipex_data.infile_d == -1 || pipex_data.outfile_d == -1)
		return (clear_pipex_data(&pipex_data), -1);
	if (pipe(pipex_data.pipe) == -1)
		return (clear_pipex_data(&pipex_data), -1);
	pid1 = fork();
	if (pid1 == 0)
		first_process(&pipex_data, argv[2], envp);
	pid2 = fork();
	if (pid2 == 0)
		second_process(&pipex_data, argv[3], envp);
	waitpid(pid1, NULL, WNOHANG);
	waitpid(pid2, NULL, WNOHANG);
	clear_pipex_data(&pipex_data);
	system("leaks test");
	return (0);
}
