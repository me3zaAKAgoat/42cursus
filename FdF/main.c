/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:19:10 by echoukri          #+#    #+#             */
/*   Updated: 2023/02/24 19:01:44 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	rotated_point(t_meta_data *fdf, t_point point)
{
	t_point	end_point;
	double matrix_x[] = {1, 0, 0, 0, cos(fdf->deg_rota_about_x), -sin(fdf->deg_rota_about_x), 0, sin(fdf->deg_rota_about_x), cos(fdf->deg_rota_about_x)};
	double matrix_y[] = {cos(fdf->deg_rota_about_y), 0, sin(fdf->deg_rota_about_y), 0, 1, 0, -sin(fdf->deg_rota_about_y), 0, cos(fdf->deg_rota_about_y)};
	double matrix_z[] = {cos(fdf->deg_rota_about_z), -sin(fdf->deg_rota_about_z), 0, sin(fdf->deg_rota_about_z), cos(fdf->deg_rota_about_z), 0, 0, 0, 1};

	end_point = apply_matrix(point, matrix_x);
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

void	draw_horizontal_lines(t_meta_data *fdf, int index)
{
	int	next_index;

	next_index = index + 1;
	if (fdf->points[next_index].x == (fdf->points[index].x + 1))
		bresenham(fdf,
			rotated_point(fdf, scaled_point(fdf, fdf->points[index])),
			rotated_point(fdf, scaled_point(fdf, fdf->points[next_index])));
}

void	draw_vertical_lines(t_meta_data *fdf, int index)
{
	int	next_index;

	next_index = index + fdf->heights[fdf->points[index].y];
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
	index = 0;
	while (index < fdf->nbr_of_points)
	{
		draw_horizontal_lines(fdf, index);
		index++;
	}
	index = 0;
	while (index < fdf->nbr_of_points)
	{
		draw_vertical_lines(fdf, index);
		index++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
}

void	handle_directional_key_press(int key, double rota_unit,
		t_meta_data *fdf)
{
	if (key == KEY_LEFT)
		fdf->deg_rota_about_y -= rota_unit;
	if (key == KEY_RIGHT)
		fdf->deg_rota_about_y += rota_unit;
	if (key == KEY_UP)
		fdf->deg_rota_about_x += rota_unit;
	if (key == KEY_DOWN)
		fdf->deg_rota_about_x -= rota_unit;
	draw_frame(fdf);
}

void	handle_translation_key_press(int key, int translation_unit,
		t_meta_data *fdf)
{
	if (key == KEY_W && (fdf->y_translation - translation_unit > -(HEIGHT / 2)))
		fdf->y_translation -= translation_unit;
	if (key == KEY_D && (fdf->x_translation + translation_unit <= (WIDTH / 2)))
		fdf->x_translation += translation_unit;
	if (key == KEY_S && (fdf->y_translation + translation_unit <= (HEIGHT / 2)))
		fdf->y_translation += translation_unit;
	if (key == KEY_A && (fdf->x_translation - translation_unit > -(WIDTH / 2)))
		fdf->x_translation -= translation_unit;
	draw_frame(fdf);
}

int	handle_key_press(int key, t_meta_data *fdf)
{	
	double	rota_unit;
	int		translation_unit;

	rota_unit = 0.03;
	translation_unit = 30;
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN)
		handle_directional_key_press(key, rota_unit, fdf);
	if (key == KEY_W || key == KEY_D || key == KEY_S || key == KEY_A)
		handle_translation_key_press(key, translation_unit, fdf);
	return (0);
}

int	handle_zoom(int key, int x, int y, t_meta_data *fdf)
{	
	int	unit;

	unit = 1;
	if (key == ZOOM_OUT)
	{			
		if (fdf->scale_factor - unit <= 0)
			return (0);
		fdf->scale_factor -= unit;
	}
	else if (key == ZOOM_IN)
		fdf->scale_factor += unit;
	draw_frame(fdf);
	return (0);
}

void	struct_init(t_meta_data *fdf, char **argv)
{
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Fil De Fer");
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	read_map(fdf, argv[1]);
	fdf->scale_factor = 1;
	fdf->deg_rota_about_x = 0;
	fdf->deg_rota_about_y = 0;
	fdf->deg_rota_about_z = 0;
	fdf->x_translation = 0;
	fdf->y_translation = 0;
}

int	main(int ac, char **argv)
{
	t_meta_data	fdf;

	struct_init(&fdf, argv);
	draw_frame(&fdf);
	mlx_hook(fdf.mlx_win, 2, 1L, handle_key_press, &fdf);
	mlx_mouse_hook(fdf.mlx_win, handle_zoom, &fdf);
	mlx_loop(fdf.mlx);
}