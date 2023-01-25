/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:19:10 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/25 17:36:29 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_cube(t_meta_data *fdf)
{
	fdf->points[0].x = -1 * fdf->scale_factor;
	fdf->points[0].y = 1 * fdf->scale_factor;
	fdf->points[0].z = -1 * fdf->scale_factor;
	fdf->points[0].color = 0x001d6ef0;
	fdf->points[1].x = 1 * fdf->scale_factor;
	fdf->points[1].y = 1 * fdf->scale_factor;
	fdf->points[1].z = -1 * fdf->scale_factor;
	fdf->points[1].color = 0x001d6ef0;
	fdf->points[2].x = 1 * fdf->scale_factor;
	fdf->points[2].y = -1 * fdf->scale_factor;
	fdf->points[2].z = -1 * fdf->scale_factor;
	fdf->points[2].color = 0x00db14cb;
	fdf->points[3].x = -1 * fdf->scale_factor;
	fdf->points[3].y = -1 * fdf->scale_factor;
	fdf->points[3].z = -1 * fdf->scale_factor;
	fdf->points[3].color = 0x00db14cb;
	fdf->points[4].x = -1 * fdf->scale_factor;
	fdf->points[4].y = -1 * fdf->scale_factor;
	fdf->points[4].z = 1 * fdf->scale_factor;
	fdf->points[4].color = 0x003cdb14;
	fdf->points[5].x = 1 * fdf->scale_factor;
	fdf->points[5].y = -1 * fdf->scale_factor;
	fdf->points[5].z = 1 * fdf->scale_factor;
	fdf->points[5].color = 0x003cdb14;
	fdf->points[6].x = 1 * fdf->scale_factor;
	fdf->points[6].y = 1 * fdf->scale_factor;
	fdf->points[6].z = 1 * fdf->scale_factor;
	fdf->points[6].color = 0x00db1425;
	fdf->points[7].x = -1 * fdf->scale_factor;
	fdf->points[7].y = 1 * fdf->scale_factor;
	fdf->points[7].z = 1 * fdf->scale_factor;
	fdf->points[7].color = 0x00db1425;
}

t_point rotated_point(t_meta_data *fdf, t_point point)
{
	t_point end_point;

	double matrix_x[] = {1, 0, 0, 0, cos(fdf->deg_rota_about_x), -sin(fdf->deg_rota_about_x), 0, sin(fdf->deg_rota_about_x), cos(fdf->deg_rota_about_x)};
	double matrix_y[] = {cos(fdf->deg_rota_about_y), 0, sin(fdf->deg_rota_about_y), 0, 1, 0, -sin(fdf->deg_rota_about_y), 0, cos(fdf->deg_rota_about_y)};
	double matrix_z[] = {cos(fdf->deg_rota_about_z), -sin(fdf->deg_rota_about_z), 0, sin(fdf->deg_rota_about_z), cos(fdf->deg_rota_about_z), 0, 0, 0, 1};
	end_point =	apply_matrix(point, matrix_x);
	end_point = apply_matrix(end_point, matrix_y);
	end_point = apply_matrix(end_point, matrix_z);
	return (end_point);
}

int	handle_key_press(int key, t_meta_data *fdf)
{	
	if (key == KEY_LEFT)
	{	
		fdf->deg_rota_about_y -= 0.1;
		mlx_destroy_image(fdf->mlx, fdf->img.img);
		mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	}
	else if (key == KEY_RIGHT)
	{
		fdf->deg_rota_about_y += 0.1;
		mlx_destroy_image(fdf->mlx, fdf->img.img);
		mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	}
	else if (key == KEY_UP)
	{	
		fdf->deg_rota_about_x += 0.1;
		mlx_destroy_image(fdf->mlx, fdf->img.img);
		mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	}
	else if (key == KEY_DOWN)
	{
		fdf->deg_rota_about_x -= 0.1;
		mlx_destroy_image(fdf->mlx, fdf->img.img);
		mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	}
	return 0;
}


int main(int ac, char **argv)
{
	t_meta_data fdf;

	fdf.mlx = mlx_init();
	fdf.mlx_win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "Fil De Fer");
	fdf.img.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel, &fdf.img.line_length, &fdf.img.endian);
	fdf.scale_factor = 50;
	fdf.points = malloc(8 * sizeof(t_point));
	fdf.nbr_of_points = 8;
	fdf.deg_rota_about_x = 0;
	fdf.deg_rota_about_y = 0;
	fdf.deg_rota_about_z = 0;
	read_map(&fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img.img, 0, 0);
	mlx_key_hook(fdf.mlx_win, handle_key_press, &fdf);
	mlx_loop(fdf.mlx);
}