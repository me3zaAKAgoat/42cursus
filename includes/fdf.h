/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:04:26 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/28 16:01:42 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define WIDTH 1920
# define HEIGHT 1080

# define KEY_LEFT    123
# define KEY_RIGHT   124
# define KEY_DOWN    125
# define KEY_UP      126

typedef struct	point {
	int	x;
	int	y;
	int	z;
	int color;
}	t_point;

typedef struct img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct meta_data {
	t_point		*points;
	int			nbr_of_points;
	double		deg_rota_about_x;
	double		deg_rota_about_y;
	double		deg_rota_about_z;
	int			scale_factor;
	t_img_data	img;
	void		*mlx;
	void		*mlx_win;
}	t_meta_data;

extern int	ft_strlen(char *str);
extern t_point	apply_matrix(t_point	old_point, double	matrix[]);
extern void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
extern void	bresenham(t_img_data *img, t_point a, t_point b, int color);
extern char	*get_next_line(int fd);
extern int	ft_atoi_base(char *str, char *base);
extern char	*ft_substr(char const *s, unsigned int start, size_t len);
extern char	**ft_split(char const *s, char c);
extern void	*split_clear(char	**arr);


#endif