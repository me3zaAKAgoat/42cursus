#include <mlx.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1600
#define HEIGHT 900

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y > HEIGHT || y < 0)
		y = 0;
	if (x > WIDTH || x < 0)
		x = 0;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

typedef struct	point {
	int	x;
	int	y;
	int	z;
}	point;

void	apply_matrix(point	*old_point, double	matrix[])
{
	point	new_point;

	new_point.x = old_point->x * matrix[0] + old_point->y * matrix[1] + old_point->z * matrix[2];
	new_point.y = old_point->x * matrix[3] + old_point->y * matrix[4] + old_point->z * matrix[5];
	new_point.z = old_point->x * matrix[6] + old_point->y * matrix[7] + old_point->z * matrix[8];
	*old_point = new_point;
}

void bresenham(t_data*img, point a, point b, int color, int offset_x, int offset_y) {
	int delta_x = abs(b.x - a.x);
	int delta_y = abs(b.y - a.y);
	int sx = a.x < b.x ? 1 : -1;
	int sy = a.y < b.y ? 1 : -1;
	int err = delta_x - delta_y;

	while(1) {
		// draw the current pixel
		my_mlx_pixel_put(img, offset_x + a.x, offset_y + a.y, color);
		if (a.x == b.x && a.y == b.y) break;
		int e2 = 2 * err;
		if (e2 > -delta_y) {
			err -= delta_y;
			a.x += sx;
		}
		if (e2 < delta_x) {
			err += delta_x;
			a.y += sy;
		}
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int	unit = 100;
	int offset_x = WIDTH / 2;
	int offset_y = HEIGHT / 2;
	point	a;
	point	b;
	point	c;
	point	d;
	point	e;
	point	f;
	point	g;
	point	h;
	double deg = 0;
	while (1)
	{

		double matrix_x[] = {1, 0, 0, 0, cos(deg), -sin(deg), 0, sin(deg), cos(deg)};
		double matrix_y[] = {cos(deg), 0, sin(deg), 0, 1, 0, -sin(deg), 0, cos(deg)};
		double matrix_z[] = {cos(deg), -sin(deg), 0, sin(deg), cos(deg), 0, 0, 0, 1};

		a.x = -1 * unit;
		a.y = 1 * unit;
		a.z = -1 * unit;
		b.x = 1 * unit;
		b.y = 1 * unit;
		b.z = -1 * unit;
		c.x = 1 * unit;
		c.y = -1 * unit;
		c.z = -1 * unit;
		d.x = -1 * unit;
		d.y = -1 * unit;
		d.z = -1 * unit;
		e.x = -1 * unit;
		e.y = 1 * unit;
		e.z = 1 * unit;
		f.x = 1 * unit;
		f.y = 1 * unit;
		f.z = 1 * unit;
		g.x = 1 * unit;
		g.y = -1 * unit;
		g.z = 1 * unit;
		h.x = -1 * unit;
		h.y = -1 * unit;
		h.z = 1 * unit;


		//x
		apply_matrix(&a, matrix_x);
		apply_matrix(&b, matrix_x);
		apply_matrix(&c, matrix_x);
		apply_matrix(&d, matrix_x);
		apply_matrix(&e, matrix_x);
		apply_matrix(&f, matrix_x);
		apply_matrix(&g, matrix_x);
		apply_matrix(&h, matrix_x);
		//y
		apply_matrix(&a, matrix_y);
		apply_matrix(&b, matrix_y);
		apply_matrix(&c, matrix_y);
		apply_matrix(&d, matrix_y);
		apply_matrix(&e, matrix_y);
		apply_matrix(&f, matrix_y);
		apply_matrix(&g, matrix_y);
		apply_matrix(&h, matrix_y);
		//z
		apply_matrix(&a, matrix_z);
		apply_matrix(&b, matrix_z);
		apply_matrix(&c, matrix_z);
		apply_matrix(&d, matrix_z);
		apply_matrix(&e, matrix_z);
		apply_matrix(&f, matrix_z);
		apply_matrix(&g, matrix_z);
		apply_matrix(&h, matrix_z);
		my_mlx_pixel_put(&img, offset_x + a.x, offset_y + a.y, 0x00FF0000);
		my_mlx_pixel_put(&img, offset_x + b.x, offset_y + b.y, 0x00FF0000);
		my_mlx_pixel_put(&img, offset_x + c.x, offset_y + c.y, 0x00FF0000);
		my_mlx_pixel_put(&img, offset_x + d.x, offset_y + d.y, 0x00FF0000);
		my_mlx_pixel_put(&img, offset_x + e.x, offset_y + e.y, 0x00FF0000);
		my_mlx_pixel_put(&img, offset_x + f.x, offset_y + f.y, 0x00FF0000);
		my_mlx_pixel_put(&img, offset_x + g.x, offset_y + g.y, 0x00FF0000);
		my_mlx_pixel_put(&img, offset_x + h.x, offset_y + h.y, 0x00FF0000);
		bresenham(&img, a, b, 0x0000FF00, offset_x, offset_y);
		bresenham(&img, b, c, 0x0000FF00, offset_x, offset_y);
		bresenham(&img, c, d, 0x0000FF00, offset_x, offset_y);
		bresenham(&img, d, a, 0x0000FF00, offset_x, offset_y);
		bresenham(&img, e, f, 0x00FF0000, offset_x, offset_y);
		bresenham(&img, f, g, 0x00FF0000, offset_x, offset_y);
		bresenham(&img, g, h, 0x00FF0000, offset_x, offset_y);
		bresenham(&img, h, e, 0x00FF0000, offset_x, offset_y);
		bresenham(&img, a, e, 0x00F0DE1A, offset_x, offset_y);
		bresenham(&img, b, f, 0x00F0DE1A, offset_x, offset_y);
		bresenham(&img, c, g, 0x00D115D1, offset_x, offset_y);
		bresenham(&img, d, h, 0x00D115D1, offset_x, offset_y);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		// sleep(1);
		mlx_destroy_image(mlx, img.img);
		img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
		deg += 0.001;
	}
	mlx_loop(mlx);
}