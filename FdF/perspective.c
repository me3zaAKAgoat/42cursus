/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:31:34 by echoukri          #+#    #+#             */
/*   Updated: 2023/02/01 18:34:56 by echoukri         ###   ########.fr       */
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
