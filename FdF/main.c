/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:19:10 by echoukri          #+#    #+#             */
/*   Updated: 2023/02/01 18:30:09 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	rotated_point(t_meta_data *fdf, t_point point)
{
	t_point	end_point;
	double matrix_x[] = {1, 0, 0, 0, cos(fdf->deg_rota_about_x), -sin(fdf->deg_rota_about_x), 0, sin(fdf->deg_rota_about_x), cos(fdf->deg_rota_about_x)};
	double matrix_y[] = {cos(fdf->deg_rota_about_y), 0, sin(fdf->deg_rota_about_y), 0, 1, 0, -sin(fdf->deg_rota_about_y), 0, cos(fdf->deg_rota_about_y)};
	double matrix_z[] = {cos(fdf->deg_rota_about_z), -sin(fdf->deg_rota_about_z), 0, sin(fdf->deg_rota_about_z), cos(fdf->deg_rota_about_z), 0, 0, 0, 1};

	end_point =	apply_matrix(point, matrix_x);
	end_point = apply_matrix(end_point, matrix_y);
	end_point = apply_matrix(end_point, matrix_z);
	return (end_point);
}

t_point	scaled_point(t_meta_data *fdf, t_point point)
{
	t_point	end_point;

	end_point.x = point.x * fdf->scale_factor;
	end_point.y = point.y * fdf->scale_factor;
	end_point.z = point.z * fdf->scale_factor;
	return (end_point);
}

void	draw_pts_to_image(t_meta_data *fdf)
{
	int	point_index;

	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	point_index = 0;
	while (point_index < fdf->nbr_of_points)
	{
		add_pixel_to_frame(&fdf->img,
			rotated_point(fdf, scaled_point(fdf, fdf->points[point_index])).x,
			rotated_point(fdf, scaled_point(fdf, fdf->points[point_index])).y,
			fdf->points[point_index].color);
		point_index++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
}

int	handle_key_press(int key, t_meta_data *fdf)
{	
	if (key == KEY_LEFT)
	{	
		fdf->deg_rota_about_y -= 0.06;
		draw_pts_to_image(fdf);
	}
	if (key == KEY_RIGHT)
	{
		fdf->deg_rota_about_y += 0.06;
		draw_pts_to_image(fdf);
	}
	if (key == KEY_UP)
	{	
		fdf->deg_rota_about_x += 0.06;
		draw_pts_to_image(fdf);
	}
	if (key == KEY_DOWN)
	{
		fdf->deg_rota_about_x -= 0.06;
		draw_pts_to_image(fdf);
	}
	return (0);
}

int	handle_zoom(int key, int x, int y, t_meta_data *fdf)
{	
	if (key == ZOOM_OUT)
	{			
		if (fdf->scale_factor - 1 <= 0)
			return (0);
		fdf->scale_factor -= 1;
		draw_pts_to_image(fdf);
	}
	else if (key == ZOOM_IN)
	{	
		fdf->scale_factor += 1;
		draw_pts_to_image(fdf);
	}
	return (0);
}

void	struct_init(t_meta_data *fdf, char **argv)
{
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Fil De Fer");
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	fdf->scale_factor = 1;
	fdf->deg_rota_about_x = 0;
	fdf->deg_rota_about_y = 0;
	fdf->deg_rota_about_z = 0;
	read_map(fdf, argv[1]);
}

int	main(int ac, char **argv)
{
	t_meta_data	fdf;
	int			max_y;
	int			max_x;
	int			i = 0;

	struct_init(&fdf, argv);
	max_x = fdf.points[0].x;
	max_y = fdf.points[0].y;
	while (i < fdf.nbr_of_points)
	{
		if (fdf.points[i].x > max_x)
			max_x = fdf.points[i].x;
		if (fdf.points[i].y > max_y)
			max_y = fdf.points[i].y;
		i++;
	}
	draw_pts_to_image(&fdf);
	mlx_hook(fdf.mlx_win, 2, 1L, handle_key_press, &fdf);
	mlx_mouse_hook(fdf.mlx_win, handle_zoom, &fdf);
	mlx_loop(fdf.mlx);
}
