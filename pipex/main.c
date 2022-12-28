/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:47:32 by echoukri          #+#    #+#             */
/*   Updated: 2022/12/28 00:55:45 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
void	child_process(int	infiled, int	*vpipe,	char *path)
{
	char	*cmd;

	dup2(STDIN_FILENO, infiled);
	execve();
}

void	pipex(int	infiled, int	outfiled, char	*envp)
{
	int		vpipe[2];
	int		pres;
	pid_t	fres;
	char	*path;

	pres = pipe(vpipe);
	fres = fork();
	if (fres == -1)
		return (perror("errno at fork is:"));
	else if (fres == 0)
	{
		path = get_path(envp);
		child_process(infiled, vpipe, path);
	}
	else if (fres > 0)
	{
		
	}
}

int	main(int ac, char *argv[], char *envp[])
{
	int	infiled;
	int	outfiled;
	int	*parsed_arr;

	parsed_arr = file_opener(argv[1], argv[4]);
	infiled = *(parsed_arr);
	outfiled = *(parsed_arr + 1);
	if (infiled == -1 || outfiled == -1)
		return (-1);
	pipex(infiled, outfiled, envp);
	return (0);
}

// how should I guard pipe failure
// how should I guard duplication failure
/*first command reads from infile and runs in a child process
first command then sends output to parent processes pipr
the parent process readd from the pipe and sendd the output to outfile*/