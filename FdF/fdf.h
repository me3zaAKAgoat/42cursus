/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:04:26 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/24 13:05:46 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1920
#define HEIGHT 1080

typedef struct	point {
	int	x;
	int	y;
	int	z;
}	point;

typedef struct img_data {
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_img_data;

typedef struct meta_data {
    point       *points;
    int         nbr_of_points;
    double      deg;
    int         scale_factor;
    t_img_data  *img;
    void        *mlx;
    void        *mlx_win;
}   t_meta_data;