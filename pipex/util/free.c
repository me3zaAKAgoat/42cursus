/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:33:03 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/04 13:54:37 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	clear_pipex_data(t_pipex_obj	*pipex_data, int ac)
{
	size_t		i;
	size_t		s_arr;

	i = 0;
	s_arr = sizeof(int) * 2 * (ac - 4);
	while (i < s_arr)
	{
		close(pipex_data->pipes[i]);
		i++;
	}
	free(pipex_data->pipes);
	close(pipex_data->infile_d);
	close(pipex_data->outfile_d);
	split_clear(pipex_data->program_paths);
}
