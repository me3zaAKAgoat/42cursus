/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:33:03 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/03 14:43:29 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	clear_pipex_data(t_pipex_obj	*pipex_data)
{
	close(pipex_data->infile_d);
	close(pipex_data->outfile_d);
	close(pipex_data->pipe[0]);
	close(pipex_data->pipe[1]);
	split_clear(pipex_data->program_paths);
}
