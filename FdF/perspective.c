/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:31:34 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/01 18:39:51 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	apply_matrix(t_point old_point, double matrix[])
{
	t_point	new_point;

	new_point.x = old_point.x * matrix[0]
		+ old_point.y * matrix[1] + old_point.z * matrix[2];
	new_point.y = old_point.x * matrix[3]
		+ old_point.y * matrix[4] + old_point.z * matrix[5];
	new_point.z = old_point.x * matrix[6]
		+ old_point.y * matrix[7] + old_point.z * matrix[8];
	return (new_point);
}

void	set_base_perspective(t_meta_data *fdf)
{
	fdf->plane_scale_factor = 50;
	fdf->z_scale_factor = 50;
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


