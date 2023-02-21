/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:32:34 by echoukri          #+#    #+#             */
/*   Updated: 2023/02/21 11:48:14 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	alloc_members(t_meta_data *fdf, char *file_name)
{
	int		fd;
	int		non_spc_nl_count;
	char	*str;
	t_point	*points;
	int		nbr_of_lines;

	non_spc_nl_count = 0;
	nbr_of_lines = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		perr_exit("cant open map file");
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		else
		{
			nbr_of_lines += 1;
			non_spc_nl_count += count_words(str, ' ') - 1;
		}
		free(str);
	}
	close(fd);
	fdf->points = malloc(non_spc_nl_count * sizeof(t_point));
	if (fdf->points == NULL)
		perr_exit("couldn't malloc for array of points");
	fdf->heights = malloc(sizeof(int) * nbr_of_lines);
	if (fdf->heights == NULL)
		perr_exit("couldn't malloc for array of heights");
}

void	set_point_color(char **split_line, t_point *point_to_color, int x)
{
	char	**z_color;

	if (ft_strchr(split_line[x], ',') != NULL)
	{
		z_color = ft_split(split_line[x], ',');
		(*point_to_color).color = ft_atoi_base(z_color[1] + 2,
				"0123456789ABCDEF");
		split_clear(z_color);
	}
	else
		(*point_to_color).color = 0x00FFFFFF;
}

void	register_line(int y, char *str, t_meta_data *fdf)
{
	int		x;
	int		line_length;
	char	**split_line;
	t_point	point;

	split_line = ft_split(str, ' ');
	if (split_line == NULL)
		perr_exit("error in spliting a seperarte line");
	free(str);
	str = NULL;
	line_length = 0;
	while (split_line[line_length])
		line_length++;
	*(fdf->heights + y) = line_length;
	x = 0;
	while (x < line_length)
	{
		point.x = x * 1;
		point.y = y * 1;
		point.z = ft_atoi_base(split_line[x], "0123456789") * 0.8;
		set_point_color(split_line, &point, x);
		*(fdf->points + fdf->nbr_of_points + x) = point;
		x++;
	}
	split_clear(split_line);
	fdf->nbr_of_points += line_length;
}

void	read_map(t_meta_data *fdf, char *file_name)
{
	int		fd;
	char	*str;
	int		y;

	str = NULL;
	alloc_members(fdf, file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		perr_exit("cant open map file");
	y = 0;
	fdf->nbr_of_points = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		else
			register_line(y, str, fdf);
		y += 1;
	}
	puts("read map succesfully");
}
