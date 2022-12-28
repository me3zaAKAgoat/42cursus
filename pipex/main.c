/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:47:32 by echoukri          #+#    #+#             */
/*   Updated: 2022/12/28 05:30:43 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//handle file opening failure
int	*file_opener(char *fn1, char *fn2)
{
	int	arr[2];
	int	err;

	err = -1;
	arr[0] = open(fn1, O_RDONLY);
	if (arr[0] < 0)
	{
		perror("error opening file 1");
		return (&err);
	}
	arr[1] = open(fn2, O_WRONLY);
	if (arr[1] < 0)
	{
		perror("error opening file 2");
		return (&err);
	}
	return (arr);
}

// switch STDIN with vpipe[0] then execute 
// check dup2 failure
void	child_process(int infiled, int *vpipe,	char *cmd, char *envp)
{
	char	*cmd_path;
	char	*cmd_args;
	char	*tmp;

	dup2(STDIN_FILENO, infiled);
	tmp = ft_split(cmd, ' ');
	cmd_path = get_cmd(get_paths(envp), cmd[0]);
	execve(cmd, cmd_args, envp);
}

void	pipex(int infiled, int outfiled, char *cmd1, char *cmd2 , char *envp)
{
	int		vpipe[2];
	int		pres;
	pid_t	fres;
	char	*cmd;

	pres = pipe(vpipe);
	fres = fork();
	if (fres == -1)
		return (perror("errno at fork is:"));
	else if (fres == 0)
	{
		child_process(infiled, vpipe, cmd1, envp);
	}
	else if (fres > 0)
	{
		
	}
}

// handle other function failures
int	main(int ac, char *argv[], char *envp[])
{
	int	infiled;
	int	outfiled;
	int	*descriptors;

	descriptors = file_opener(argv[1], argv[4]);
	infiled = *(descriptors);
	outfiled = *(descriptors + 1);
	if (infiled == -1 || outfiled == -1)
		return (-1);
	pipex(infiled, outfiled, argv[2], argv[3], envp);
	return (0);
}

// how should I guard pipe failure
// how should I guard duplication failure
/*first command reads from infile and runs in a child process
first command then sends output to parent processes pipr
the parent process readd from the pipe and sendd the output to outfile*/
