/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:31:34 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/24 10:31:50 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_matrix(point	*old_point, double	matrix[])
{
	point	new_point;

	new_point.x = old_point->x * matrix[0] + old_point->y * matrix[1] + old_point->z * matrix[2];
	new_point.y = old_point->x * matrix[3] + old_point->y * matrix[4] + old_point->z * matrix[5];
	new_point.z = old_point->x * matrix[6] + old_point->y * matrix[7] + old_point->z * matrix[8];
	*old_point = new_point;
}
