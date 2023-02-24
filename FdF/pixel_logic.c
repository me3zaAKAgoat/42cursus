/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:32:19 by echoukri          #+#    #+#             */
/*   Updated: 2023/02/24 19:06:57 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# define MAX(a,b) (((a) > (b)) ? (a) : (b))
# define MIN(a, b) ((a) < (b) ? (a) : (b))

void	add_pixel_to_frame(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	x += WIDTH / 2;
	y += HEIGHT / 2;
	if ((y >= HEIGHT || y <= 0) || (x >= WIDTH || x <= 0))
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham(t_meta_data *fdf, t_point a, t_point b)
{
	int	delta_x;
	int	delta_y;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	delta_x = abs(b.x - a.x);
	delta_y = abs(b.y - a.y);
	sx = a.x < b.x ? 1 : -1;
	sy = a.y < b.y ? 1 : -1;
	err = delta_x - delta_y;
	while (1)
	{
		add_pixel_to_frame(&fdf->img, a.x + fdf -> x_translation, a.y + fdf-> y_translation, a.color);
		if (a.x == b.x && a.y == b.y) break;
		e2 = 2 * err;
		if (e2 > -delta_y)
		{
			err -= delta_y;
			a.x += sx;
		}
		if (e2 < delta_x)
		{
			err += delta_x;
			a.y += sy;
		}
	}
}


// {
// 	int delta_x = abs(b.x - a.x);
// 	int delta_y = abs(b.y - a.y);
// 	int sx = a.x < b.x ? 1 : -1;
// 	int sy = a.y < b.y ? 1 : -1;
// 	int err = delta_x - delta_y;

// 	while (1) {
// 		add_pixel_to_frame(&fdf->img, a.x + fdf -> x_translation, a.y + fdf-> y_translation, a.color);
// 		if (a.x == b.x && a.y == b.y) break;
// 		int e2 = 2 * err;
// 		if (e2 > -delta_y) {
// 			err -= delta_y;
// 			a.x += sx;
// 		}
// 		if (e2 < delta_x) {
// 			err += delta_x;
// 			a.y += sy;
// 		}
// 	}
// }
