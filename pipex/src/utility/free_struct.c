/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:33:03 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/19 03:43:14 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
serves as a cleanup function that frees mallcoated space for pipes.
*/

void	free_struct(t_pipex_obj	*pipex_data)
{
	free(pipex_data->pipes);
	split_clear(pipex_data->program_paths);
}
