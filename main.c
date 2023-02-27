/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:19:10 by echoukri          #+#    #+#             */
/*   Updated: 2023/02/27 17:15:35 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_base_perspective(t_meta_data *fdf)
{
	fdf->plane_scale_factor = 10;
	fdf->z_scale_factor = 10;
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->x_translation = 0;
	fdf->y_translation = 0;
}


t_point	rotated_point(t_meta_data *fdf, t_point point)
{
	t_point	new_point;
	double matrix_x[] = {1, 0, 0, 0, cos(fdf->alpha), -sin(fdf->alpha), 0, sin(fdf->alpha), cos(fdf->alpha)};
	double matrix_y[] = {cos(fdf->beta), 0, sin(fdf->beta), 0, 1, 0, -sin(fdf->beta), 0, cos(fdf->beta)};

	new_point = apply_matrix(point, matrix_x);
	new_point = apply_matrix(new_point, matrix_y);
	new_point.color = point.color;
	return (new_point);
}

t_point	scaled_point(t_meta_data *fdf, t_point point)
{
	t_point	new_point;

	new_point.x = point.x * fdf->plane_scale_factor;
	new_point.y = point.y * fdf->plane_scale_factor;
	new_point.z = point.z * fdf->z_scale_factor;
	new_point.color = point.color;
	return (new_point);
}

void	draw_instructions(t_meta_data *fdf)
{
	int	i;

	i = 0;
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10, (++i * 30), 0xf0453c, "COORDINATES");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10, (++i * 30), 0xFFFFFF, "X    : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10, (i * 30), 0x30f21b, ft_itoa(fdf->x_translation));
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10, (++i * 30), 0xFFFFFF, "Y    : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10, (i * 30), 0x30f21b, ft_itoa(-fdf->y_translation));
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10, (++i * 30), 0xFFFFFF, "ZOOM : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10, (i * 30), 0x30f21b, ft_itoa(fdf->plane_scale_factor));
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10, (++i * 30), 0xFFFFFF, "ALPHA: ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10, (i * 30), 0x30f21b, ft_dtoa(fdf->alpha, 2));
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10, (++i * 30), 0xFFFFFF, "BETA : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10, (i * 30), 0x30f21b, ft_dtoa(-fdf->beta, 2));
	i+= 12;
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10, (++i * 30), 0xf0453c, "CONTROLS");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10, (++i * 30), 0xFFFFFF, "MOVE UP: W");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10, (++i * 30), 0xFFFFFF, "MOVE RIGHT: D");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10, (++i * 30), 0xFFFFFF, "MOVE DOWN: S");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10, (++i * 30), 0xFFFFFF, "MOVE LEFT: A");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10, (++i * 30), 0xFFFFFF, "ROTATE: ARROW KEYS");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10, (++i * 30), 0xFFFFFF, "RESET: ENTER");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10, (++i * 30), 0xFFFFFF, "QUIT: ESCAPE");
}

void	draw_horizontal_line(t_meta_data *fdf, int index)
{
	int	next_index;

	next_index = index + 1;
	if (fdf->points[next_index].x == (fdf->points[index].x + 1))
		bresenham(fdf,
			rotated_point(fdf, scaled_point(fdf, fdf->points[index])),
			rotated_point(fdf, scaled_point(fdf, fdf->points[next_index])));
}

void	draw_vertical_line(t_meta_data *fdf, int index)
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
	int width;
	int height;

	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	mlx_get_screen_size(fdf->mlx, &width, &height);
	index = 0;
	while (index < fdf->nbr_of_points)
	{
		draw_horizontal_line(fdf, index);
		index++;
	}
	index = 0;
	while (index < fdf->nbr_of_points)
	{
		draw_vertical_line(fdf, index);
		index++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	draw_instructions(fdf);
}

void	handle_directional_key_press(int key, double rota_unit,
		t_meta_data *fdf)
{
	if (key == KEY_LEFT)
		fdf->beta -= rota_unit;
	if (key == KEY_RIGHT)
		fdf->beta += rota_unit;
	if (key == KEY_UP)
		fdf->alpha += rota_unit;
	if (key == KEY_DOWN)
		fdf->alpha -= rota_unit;
	draw_frame(fdf);
}

void	handle_translation_key_press(int key, int translation_unit,
		t_meta_data *fdf)
{
	if (key == KEY_W)
		fdf->y_translation -= translation_unit;
	if (key == KEY_D)
		fdf->x_translation += translation_unit;
	if (key == KEY_S)
		fdf->y_translation += translation_unit;
	if (key == KEY_A)
		fdf->x_translation -= translation_unit;
	draw_frame(fdf);
}

void	handle_z_key_press(int key,
		t_meta_data *fdf)
{
	int	unit;

	unit = 1;
	if (key == KEY_T)
		fdf->z_scale_factor -= unit;
	if (key == KEY_Y)
		fdf->z_scale_factor += unit;
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
	if (key == KEY_ETR)
	{
		set_base_perspective(fdf);
		draw_frame(fdf);
	}
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN)
		handle_directional_key_press(key, rota_unit, fdf);
	if (key == KEY_W || key == KEY_D || key == KEY_S || key == KEY_A)
		handle_translation_key_press(key, translation_unit, fdf);
	if (key == KEY_T || key == KEY_Y)
		handle_z_key_press(key, fdf);
	return (0);
}

int	handle_zoom(int key, int x, int y, t_meta_data *fdf)
{	
	int	unit;

	unit = 1;
	if (key == ZOOM_OUT)
	{			
		if (fdf->plane_scale_factor - unit <= 0)
			return (0);
		fdf->plane_scale_factor -= unit;
	}
	else if (key == ZOOM_IN)
		fdf->plane_scale_factor += unit;
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
	set_base_perspective(fdf);
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
