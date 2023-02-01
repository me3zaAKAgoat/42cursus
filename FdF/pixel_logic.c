/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:32:19 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/31 23:46:05 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	x += WIDTH / 2;
	y += HEIGHT / 2;
	if ((y > HEIGHT || y < 0) || (x > WIDTH || x < 0))
		return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void bresenham(t_img_data *img, t_point a, t_point b, int color)
{
	int delta_x = abs(b.x - a.x);
	int delta_y = abs(b.y - a.y);
	int sx = a.x < b.x ? 1 : -1;
	int sy = a.y < b.y ? 1 : -1;
	int err = delta_x - delta_y;

	while(1) {
		// draw the current pixel
		my_mlx_pixel_put(img, a.x, a.y, color);
		if (a.x == b.x && a.y == b.y) break;
		int e2 = 2 * err;
		if (e2 > -delta_y) {
			err -= delta_y;
			a.x += sx;
		}
		if (e2 < delta_x) {
			err += delta_x;
			a.y += sy;
		}
	}
}
