/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:32:34 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/23 14:55:30 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_file(char *file_name, int *num_lines, int *num_words)
{
	int		fd;
	char	*str;

	*num_words = 0;
	*num_lines = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		perr_exit("cant open map file");
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		*num_lines += 1;
		*num_words += count_words(str, ' ') - 1;
		free(str);
	}
	close(fd);
}

void	alloc_members(t_meta_data *fdf, char *file_name)
{
	int	num_lines;
	int	num_words;

	read_file(file_name, &num_lines, &num_words);
	fdf->points = malloc(num_words * sizeof(t_point));
	if (fdf->points == NULL)
		perr_exit("couldn't malloc for array of points");
	fdf->y_lengths_arr = malloc(sizeof(int) * num_lines);
	if (fdf->y_lengths_arr == NULL)
		perr_exit("couldn't malloc for array of y_lengths_arr");
}

void	set_color(t_point *point, char	*str)
{
	char	**tmp;
	char	*color;

	if (ft_strchr(str, ',') != NULL)
	{
		tmp = ft_split(str, ',');
		color = tmp[1];
		point->color = ft_atoi_base(color + 2,
				"0123456789ABCDEF");
		if (point->color < 0x101010)
			point->color = 0x404040;
		split_clear(tmp);
	}
	else
		point->color = 0x404040;
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
	line_length = 0;
	while (split_line[line_length])
		line_length++;
	*(fdf->y_lengths_arr + y) = line_length;
	x = 0;
	while (x < line_length)
	{
		point.x = x * 1;
		point.y = y * 1;
		point.z = ft_atoi_base(split_line[x], "0123456789") * 1;
		record_max_values(fdf, point.x, point.z, point.z);
		set_color(&point, split_line[x]);
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

	write(1, LOADING_MAP_MESSAGE, ft_strlen(LOADING_MAP_MESSAGE));
	alloc_members(fdf, file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		perr_exit("cant open map file");
	y = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		register_line(y++, str, fdf);
		free(str);
	}
	write(1, SUCCESSFUL_READ_MESSAGE, ft_strlen(SUCCESSFUL_READ_MESSAGE));
}
