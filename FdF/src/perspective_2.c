/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:45:22 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/23 14:00:13 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horizontally_aligned_points(t_meta_data *fdf, int index)
{
	int	next_index;

	next_index = index + 1;
	if (fdf->points[next_index].x == (fdf->points[index].x + 1))
		bresenham(fdf,
			rotated_point(fdf, scaled_point(fdf, fdf->points[index])),
			rotated_point(fdf, scaled_point(fdf, fdf->points[next_index])));
}

void	draw_vertically_aligned_points(t_meta_data *fdf, int index)
{
	int	next_index;

	next_index = index + fdf->y_lengths_arr[fdf->points[index].y];
	if (next_index < fdf->nbr_of_points
		&& (fdf->points[index].x == fdf->points[next_index].x)
		&& (fdf->points[index].y + 1 == fdf->points[next_index].y))
		bresenham(fdf,
			rotated_point(fdf, scaled_point(fdf, fdf->points[index])),
			rotated_point(fdf, scaled_point(fdf, fdf->points[next_index])));
}

void	draw_frame(t_meta_data *fdf)
{
	int	index;

	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (fdf->img.img == NULL)
	{
		cleanup_meta_data(fdf);
		perr_exit("an mlx function call has failed");
	}
	index = 0;
	while (index < fdf->nbr_of_points)
	{
		draw_horizontally_aligned_points(fdf, index);
		index++;
	}
	index = 0;
	while (index < fdf->nbr_of_points)
	{
		draw_vertically_aligned_points(fdf, index);
		index++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	draw_menu(fdf);
}
