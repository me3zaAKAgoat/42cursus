/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:32:19 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/23 14:30:41 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pxl_to_frame(t_img_data *data, int x, int y, int color)
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

void	check_ex(t_point *current, int *delta, int sign_x, int *err)
{
	if (err[1] > -delta[1])
	{
		err[0] -= delta[1];
		current->x += sign_x;
	}
}

void	check_ey(t_point *current, int *delta, int sign_y, int *err)
{
	if (err[1] < delta[0])
	{
		err[0] += delta[0];
		current->y += sign_y;
	}
}

void	bresenham(t_meta_data *fdf, t_point a, t_point b)
{
	t_point	current;
	int		delta[2];
	int		sign[2];
	int		err[2];

	delta[0] = abs(b.x - a.x);
	delta[1] = abs(b.y - a.y);
	sign[0] = get_sign(b.x - a.x);
	sign[1] = get_sign(b.y - a.y);
	err[0] = delta[0] - delta[1];
	current = a;
	while (current.x != b.x || current.y != b.y)
	{
		pxl_to_frame(&fdf->img, current.x + fdf -> x_translation + WIDTH / 4,
			current.y + fdf-> y_translation + HEIGHT / 4,
			get_color(current, a, b, delta));
		err[1] = err[0] * 2;
		check_ex(&current, delta, sign[0], err);
		check_ey(&current, delta, sign[1], err);
	}
}
