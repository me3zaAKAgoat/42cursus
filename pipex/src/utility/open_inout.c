/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditional_open.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 04:10:31 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/19 04:17:02 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
if heredoc offset > 0
means we should open the tmp file that the heredoc provides in the working
directory
else
open the infile.
*/
int	open_in(t_pipex_obj *pipex_data)
{
	int	infile_d;

	if (pipex_data->heredoc_offset > 0)
		infile_d = open(".tmp.txt", O_RDONLY);
	else
		infile_d = open(pipex_data->argv[1], O_RDONLY);
	return (infile_d);
}

/*
if heredoc offset > 0
means we should open outfile in append mode
else
open outfile in normal mode
*/
int	open_out(t_pipex_obj *pipex_data)
{
	int	outfile_d;

	if (pipex_data->heredoc_offset > 0)
		outfile_d = open(pipex_data->argv[pipex_data->ac - 1], O_CREAT
				| O_RDWR | O_APPEND, 0000644);
	else
		outfile_d = open(pipex_data->argv[pipex_data->ac - 1], O_TRUNC | O_CREAT
				| O_RDWR, 0000644);
	return (outfile_d);
}
