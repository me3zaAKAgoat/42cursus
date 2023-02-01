/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:32:34 by echoukri          #+#    #+#             */
/*   Updated: 2023/02/01 01:57:24 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	size_t	index;

// 	if (dst < src)
// 	{
// 		index = 0;
// 		while (index < len)
// 		{
// 			*((char *)dst + index) = *((char *)src + index);
// 			index++;
// 		}
// 	}
// 	else if (src < dst)
// 	{
// 		while (len)
// 		{
// 			*((char *) dst + len - 1) = *((char *) src
// 					+ len - 1);
// 			len--;
// 		}
// 	}
// 	return (dst);
// }


// void	fill_point_coordinates(t_meta_data *fdf, int line_length)
// {
// 	int	x;

// 	x = 0;
	
// }

void	alloc_for_points(t_meta_data *fdf, char *file_name)
{
	int		fd;
	int		non_spc_nl_count;
	char	*str;

	non_spc_nl_count = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (perror("cant open map file"), exit(1));
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		else
		{
			non_spc_nl_count += count_words(str, ' ') - 1;
			free(str);
		}
	}
	fdf->points = malloc(non_spc_nl_count * sizeof(t_point));
	if (fdf->points == NULL)
	{
		perror("couldnt malloc for fdf points");
		exit(1);
	}
	close(fd);
}

void	read_map(t_meta_data *fdf, char *file_name)
{
	int		fd;
	char	*str;
	char	**split_line;
	t_point	point;
	int		line_length;
	int		x;
	int		y;
	char	**z_color;
	
	y = 0;
	fdf->nbr_of_points = 0;
	fdf->points = NULL;
	str = NULL;
	alloc_for_points(fdf, file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (perror("cant open map file"), exit(1));
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		else
		{
			split_line = ft_split(str, ' ');
			free(str);
			str = NULL;
			line_length = 0;
			while (split_line[line_length])
				line_length++;
			x = 0;
			while (x < line_length)
			{
				point.x = x * fdf->scale_factor;
				point.y = y * fdf->scale_factor;
				point.z = ft_atoi_base(split_line[x], "0123456789") * fdf->scale_factor;
				if (ft_strchr(split_line[x], ',') != NULL)
				{
					z_color = ft_split(split_line[x] , ',');
					point.color = ft_atoi_base(z_color[1] + 2, "0123456789ABCDEF");
					split_clear(z_color);
				}
				else
					point.color = 0x00FFFFFF;
				*(fdf->points + fdf->nbr_of_points + x) = point;
				x++;
			}
			split_clear(split_line);
			fdf->nbr_of_points += line_length;
			y += 1;
		}
	}
}