/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:04:26 by echoukri          #+#    #+#             */
/*   Updated: 2023/02/01 18:24:29 by echoukri         ###   ########.fr       */
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

# define WIDTH 1600
# define HEIGHT 900

//macos
// # define KEY_LEFT    123
// # define KEY_RIGHT   124
// # define KEY_DOWN    125
// # define KEY_UP      126
//ubuntu
# define KEY_UP      65362
# define KEY_RIGHT   65363
# define KEY_DOWN    65364
# define KEY_LEFT    65361

//mouse events
# define ZOOM_IN    4
# define ZOOM_OUT   5

# define BASE_SCALE 20

typedef struct point {
	int	x;
	int	y;
	int	z;
	int	color;
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

extern void		perr_exit(char *msg);
extern int		count_words(char const *s, char c);
extern size_t	ft_strlen(const char *s);
extern t_point	apply_matrix(t_point old_point, double matrix[]);
extern void		add_pixel_to_frame(t_img_data *data, int x, int y, int color);
extern void		bresenham(t_img_data *img, t_point a, t_point b);
extern char		*get_next_line(int fd);
extern int		ft_atoi_base(char *str, char *base);
extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern char		**ft_split(char const *s, char c);
extern void		*split_clear(char	**arr);
extern void		read_map(t_meta_data *fdf, char *file_name);
extern char		*ft_strchr(const char *s, int c);

#endif