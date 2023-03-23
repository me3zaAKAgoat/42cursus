/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:19:10 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/23 19:53:42 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	struct_init(t_meta_data *fdf, char **argv)
{
	fdf->max_x = 0;
	fdf->max_y = 0;
	fdf->max_z = 0;
	fdf->nbr_of_points = 0;
	read_map(fdf, argv[1]);
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		return (free(fdf->y_lengths_arr), free(fdf->points),
			perr_exit("an mlx function call has failed"), hacky_void());
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Fil De Fer");
	if (fdf->mlx_win == NULL)
		return (free(fdf->y_lengths_arr), free(fdf->points),
			perr_exit("an mlx function call has failed"), hacky_void());
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (fdf->img.img == NULL)
		return (cleanup_meta_data(fdf),
			perr_exit("an mlx function call has failed"), hacky_void());
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	if (fdf->img.addr == NULL)
		return (cleanup_meta_data(fdf),
			perr_exit("an mlx function call has failed"), hacky_void());
}

int	main(int ac, char **argv)
{
	t_meta_data	fdf;

	if (ac != 2)
		perr_exit("incorrect number of arguments");
	struct_init(&fdf, argv);
	set_base_perspective(&fdf);
	draw_frame(&fdf);
	mlx_hook(fdf.mlx_win, 17, 0, handle_close_window, &fdf);
	mlx_hook(fdf.mlx_win, 2, 1L, handle_key_press, &fdf);
	mlx_mouse_hook(fdf.mlx_win, handle_zoom, &fdf);
	mlx_loop(fdf.mlx);
}
