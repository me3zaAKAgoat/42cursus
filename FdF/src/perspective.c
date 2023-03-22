/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:31:34 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/22 20:11:41 by echoukri         ###   ########.fr       */
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
	fdf->plane_scale_factor = 50;
	if (fdf->max_z >= 10)
		fdf->z_scale_factor = 5;
	else
		fdf->z_scale_factor = 30;
	fdf->alpha = 0.95;
	fdf->beta = -0.19;
	fdf->x_translation = 0;
	fdf->y_translation = 0;
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
	new_point.z = point.z * fdf->z_scale_factor;
	new_point.color = point.color;
	return (new_point);
}
