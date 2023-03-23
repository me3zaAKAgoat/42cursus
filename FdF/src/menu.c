/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:49:11 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/22 18:57:51 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_controls_menu(t_meta_data *fdf)
{
	int	i;

	i = HEIGHT / 47;
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xf0453c, "CONTROLS");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "TRANSLATE UP: W");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "TRANSLATE RIGHT: D");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "TRANSLATE DOWN: S");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "TRANSLATE LEFT: A");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "ROTATE: ARROW KEYS");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "CHANGE HEIGHT: T Y");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "RESET SHAPE: ENTER");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "QUIT: ESCAPE");
}

void	draw_angles_menu(t_meta_data *fdf, int *i)
{
	char	*str;

	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++*i * 30), 0xFFFFFF, "ALPHA: ");
	str = ft_dtoa(fdf->alpha, 2);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10,
		(*i * 30), 0x30f21b, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++*i * 30), 0xFFFFFF, "BETA : ");
	str = ft_dtoa(fdf->beta, 2);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10,
		(*i * 30), 0x30f21b, str);
	free(str);
}

void	draw_coordinates_menu(t_meta_data *fdf, int *i)
{
	char	*str;

	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++*i * 30), 0xf0453c, "COORDINATES");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++*i * 30), 0xFFFFFF, "X    : ");
	str = ft_itoa(fdf->x_translation);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10,
		(*i * 30), 0x30f21b, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++*i * 30), 0xFFFFFF, "Y    : ");
	str = ft_itoa(-fdf->y_translation);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10,
		(*i * 30), 0x30f21b, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++*i * 30), 0xFFFFFF, "ZOOM : ");
	str = ft_itoa(fdf->plane_scale_factor);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10,
		(*i * 30), 0x30f21b, str);
	free(str);
}

void	draw_menu(t_meta_data *fdf)
{
	int		i;

	i = 0;
	draw_coordinates_menu(fdf, &i);
	draw_angles_menu(fdf, &i);
	draw_controls_menu(fdf);
}
