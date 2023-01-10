/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:33:03 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/10 15:43:51 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
serves as a cleanup function that closes all the file descriptors opened
and frees mallcoated space for pipes.
*/

void	cleanup_all(t_pipex_obj	*pipex_data, int pipe_count)
{
	int		i;

	i = 0;
	while (i < pipe_count)
	{
		close(pipex_data->pipes[i]);
		i++;
	}
	free(pipex_data->pipes);
	split_clear(pipex_data->program_paths);
}
