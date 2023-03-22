/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:32:19 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/22 15:00:14 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_img(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	if ((y >= HEIGHT || y <= 0) || (x >= WIDTH || x <= 0))
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_sign(int value)
{
	if (value < 0)
		return (-1);
	if (value > 0)
		return (1);
	return (0);
}

void	bresenham(t_meta_data *fdf, t_point a, t_point b)
{
	int	delta[2];
	int	sign[2];
	int	err[2];

	delta[0] = abs(b.x - a.x);
	delta[1] = abs(b.y - a.y);
	sign[0] = get_sign(b.x - a.x);
	sign[1] = get_sign(b.y - a.y);
	err[0] = delta[0] - delta[1];
	while (a.x != b.x || a.y != b.y)
	{
		put_pixel_img(&fdf->img, a.x + fdf -> x_translation + WIDTH / 2.5,
			a.y + fdf-> y_translation + HEIGHT / 4, a.color);
		err[1] = err[0] * 2;
		if (err[1] > -delta[1])
		{
			err[0] -= delta[1];
			a.x += sign[0];
		}
		if (err[1] < delta[0])
		{
			err[0] += delta[0];
			a.y += sign[1];
		}
	}
}
