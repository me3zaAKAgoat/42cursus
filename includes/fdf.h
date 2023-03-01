/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:04:26 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/01 18:42:22 by echoukri         ###   ########.fr       */
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

// //macos
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_DOWN		125
# define KEY_UP			126
# define KEY_W			13
# define KEY_D			2
# define KEY_S			1
# define KEY_A			0
# define KEY_ESC		53
# define KEY_ETR		36
# define KEY_T		17
# define KEY_Y		16
// ubuntu
// # define KEY_UP      65362
// # define KEY_RIGHT   65363
// # define KEY_DOWN    65364
// # define KEY_LEFT    65361
// # define KEY_W 122
// # define KEY_D 100
// # define KEY_S 115
// # define KEY_A 113
// # define KEY_ESC 65307
// # define KEY_ETR 65293
// # define KEY_T 116
// # define KEY_Y 121

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
	double		alpha;
	double		beta;
	int			plane_scale_factor;
	int			z_scale_factor;
	t_img_data	img;
	void		*mlx;
	void		*mlx_win;
	int			*y_lengths_arr;
	int			x_translation;
	int			y_translation;
}	t_meta_data;

extern void		perr_exit(char *msg);
extern int		count_words(char const *s, char c);
extern size_t	ft_strlen(const char *s);
extern t_point	apply_matrix(t_point old_point, double matrix[]);
extern void		put_pixel_img(t_img_data *data, int x, int y, int color);
extern void		bresenham(t_meta_data *fdf, t_point a, t_point b);
extern char		*get_next_line(int fd);
extern char		*ft_itoa(int n);
extern char		*ft_dtoa(double num, int precision);
extern int		ft_atoi_base(char *str, char *base);
extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern char		**ft_split(char const *s, char c);
extern void		*split_clear(char	**arr);
extern void		read_map(t_meta_data *fdf, char *file_name);
extern char		*ft_strchr(const char *s, int c);
extern void		handle_directional_key_press(int key, double rota_unit,
					t_meta_data *fdf);
extern void		handle_translation_key_press(int key, int translation_unit,
					t_meta_data *fdf);
extern void		handle_z_key_press(int key, t_meta_data *fdf);
extern int		handle_key_press(int key, t_meta_data *fdf);
extern int		handle_zoom(int key, int x, int y, t_meta_data *fdf);
extern void		draw_horizontal_line(t_meta_data *fdf, int index);
extern void		draw_vertical_line(t_meta_data *fdf, int index);
extern void		draw_frame(t_meta_data *fdf);
extern void		set_base_perspective(t_meta_data *fdf);
extern t_point	rotated_point(t_meta_data *fdf, t_point point);
extern t_point	scaled_point(t_meta_data *fdf, t_point point);
extern void		draw_menu(t_meta_data *fdf);


#endif