/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:58:11 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/23 12:56:28 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	hacky_void(void)
{
	return ;
}

double	compute_progress(int start, int end, int current)
{
	if (start == end)
		return (1.0);
	return ((double)(current - start) / (end - start));
}

void	record_max_values(t_meta_data *fdf, int x, int y, int z)
{
	fdf->max_x = max(fdf->max_x, x);
	fdf->max_y = max(fdf->max_y, y);
	fdf->max_z = max(fdf->max_z, z);
}
