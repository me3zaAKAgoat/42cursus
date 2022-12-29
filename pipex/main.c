/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:47:32 by echoukri          #+#    #+#             */
/*   Updated: 2022/12/29 06:39:46 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// switch STDIN with vpipe[0] then execute 
// check dup2 failure
// tmp is base command and args wrapping array
void	first_process(int infiled, int *vpipe,	char *cmd, char *envp[])
{
	char	*cmd_path;
	char	**cmd_args;

	// dup2(infiled, STDIN_FILENO);
	// dup2(vpipe[1], STDOUT_FILENO);
	// close(vpipe[0]);
	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd(get_paths(envp), cmd_args[0]);
	printf("%s\n", cmd_path);
	execve(cmd, cmd_args, envp);
}

void	second_process(int outfiled, int *vpipe,	char *cmd, char *envp[])
{
	char	*cmd_path;
	char	**cmd_args;

	// dup2(outfiled, STDOUT_FILENO);
	// dup2(vpipe[0], STDIN_FILENO);
	// close(vpipe[1]);
	cmd_args = ft_split(cmd, ' ');
	cmd_path = get_cmd(get_paths(envp), cmd_args[0]);
	printf("%s\n", cmd_path);
	execve(cmd, cmd_args, envp);
}

// handle other function failures
int	main(int ac, char *argv[], char *envp[])
{
	int	infiled;
	int	outfiled;
	int		vpipe[2];
	int		pres;
	pid_t	pid1;
	pid_t	pid2;

	// printf("%s\n", argv[1]);
	// printf("%s\n", argv[4]);
	infiled = open(argv[1], O_RDONLY);
	outfiled = open(argv[4], O_TRUNC | O_CREAT | O_RDWR);
	// printf("%d\n", infiled);
	// printf("%d\n", outfiled);
	if (infiled == -1 || outfiled == -1)
		return (-1);
	pres = pipe(vpipe);
	pid1 = fork();
	if (pid1 == 0)
	{
		first_process(infiled, vpipe, argv[2], envp);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		second_process(outfiled, vpipe, argv[3], envp);
	}
	close(infiled);
	close(outfiled);
	close(vpipe[0]);
	close(vpipe[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
	// if (pid1 == -1)
	// 	return (perror("errno at fork is:"));
}

// how should I guard pipe failure
// how should I guard duplication failure
/*first command reads from infile and runs in a child process
first command then sends output to parent processes pipr
the parent process readd from the pipe and sendd the output to outfile*/
