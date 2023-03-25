/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:31:34 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/25 17:47:27 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	apply_matrix_alpha(t_point old_point, t_meta_data *fdf)
{
	t_point	new_point;

	new_point.x = old_point.x * 1
		+ old_point.y * 0 + old_point.z * 0;
	new_point.y = old_point.x * 0
		+ old_point.y * cos(fdf->alpha) + old_point.z * -sin(fdf->alpha);
	new_point.z = old_point.x * 0
		+ old_point.y * sin(fdf->alpha) + old_point.z * cos(fdf->alpha);
	return (new_point);
}

t_point	apply_matrix_beta(t_point old_point, t_meta_data *fdf)
{
	t_point	new_point;

	new_point.x = old_point.x * cos(fdf->beta)
		+ old_point.y * 0 + old_point.z * sin(fdf->beta);
	new_point.y = old_point.x * 0
		+ old_point.y * 1 + old_point.z * 0;
	new_point.z = old_point.x * -sin(fdf->beta)
		+ old_point.y * 0 + old_point.z * cos(fdf->beta);
	return (new_point);
}

void	set_base_perspective(t_meta_data *fdf)
{
	double window_size_x = WIDTH;
	double window_size_y = HEIGHT;

	fdf->alpha = 0.8;
	fdf->beta = 0.3;
	// Calculate scaling factors
	fdf->z_scale_factor = 1;
	while (((fdf->max_z - fdf->min_z) * fdf->z_scale_factor) / (fdf->max_x * fdf->max_x) > 0.2)
		fdf->z_scale_factor -= 0.01;
	fdf->plane_scale_factor = 1100 / max(fdf->max_x, fdf->max_y);
	if (fdf->plane_scale_factor == 1)	
		fdf->plane_scale_factor = 2;

	while (fdf->max_z * fdf->plane_scale_factor * fdf->z_scale_factor > 600)
		fdf->plane_scale_factor -= 0.01;
	fdf->x_translation = window_size_x / 2 - (fdf->max_x * fdf->plane_scale_factor) / 2;
	fdf->y_translation = window_size_y / 2 - (fdf->max_y * fdf->plane_scale_factor) / 2 + ((fdf->max_z + fdf->min_z) * fdf->plane_scale_factor * fdf->z_scale_factor) * 0.45;

	// fdf->plane_scale_factor = 0;
	// fdf->z_scale_factor = 1;
	// while ((fdf->max_x * fdf->plane_scale_factor < 1000
	// 	&& fdf->max_y * fdf->plane_scale_factor < 1000 && fdf->max_z * fdf->plane_scale_factor * fdf->z_scale_factor < 550) || fdf->plane_scale_factor < 2)
	// 	fdf->plane_scale_factor += 0.05;
	// // while ((fdf->z_scale_factor * fdf->max_z) / (fdf->max_x * fdf->max_y) >	 0.02)
	// // 	fdf->z_scale_factor -= 0.001;
	// while (fdf->max_z * fdf->plane_scale_factor * fdf->z_scale_factor > 650 && fdf->plane_scale_factor > 2)
	// 	fdf->plane_scale_factor -= 0.001;
	// fdf->x_translation = 100000 / (fdf->max_x * fdf->plane_scale_factor) ;
	// if (fdf->max_z == 0)
	// 	fdf->y_translation = 50;
	// else
	// 	fdf->y_translation = 60 + (fdf->max_z * fdf->plane_scale_factor) * 0.6;
		
}

t_point	rotated_point(t_meta_data *fdf, t_point point)
{
	t_point	new_point;

	new_point = apply_matrix_alpha(point, fdf);
	new_point = apply_matrix_beta(new_point, fdf);
	new_point.color = point.color;
	return (new_point);
}

t_point	scaled_point(t_meta_data *fdf, t_point point)
{
	t_point	new_point;

	new_point.x = point.x * fdf->plane_scale_factor;
	new_point.y = point.y * fdf->plane_scale_factor;
	new_point.z = (point.z * fdf->z_scale_factor) * fdf->plane_scale_factor;
	new_point.color = point.color;
	return (new_point);
}
