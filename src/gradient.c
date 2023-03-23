/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:47:13 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/23 13:47:26 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_weighed_value(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_point current, t_point start, t_point end, int *delta)
{
	int		red;
	int		green;
	int		blue;
	double	progress;

	if (current.color == end.color)
		return (current.color);
	if (delta[0] > delta[1])
		progress = compute_progress(start.x, end.x, current.x);
	else
		progress = compute_progress(start.y, end.y, current.y);
	red = get_weighed_value((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, progress);
	green = get_weighed_value((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, progress);
	blue = get_weighed_value(start.color & 0xFF, end.color & 0xFF, progress);
	return ((red << 16) | (green << 8) | blue);
}
