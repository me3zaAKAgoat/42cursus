/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:32:34 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/28 20:32:15 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;

	if (dst < src)
	{
		index = 0;
		while (index < len)
		{
			*((char *)dst + index) = *((char *)src + index);
			index++;
		}
	}
	else if (src < dst)
	{
		while (len)
		{
			*((char *) dst + len - 1) = *((char *) src
					+ len - 1);
			len--;
		}
	}
	return (dst);
}


void	read_map(t_meta_data *fdf)
{
	int		fd;
	char	*str;
	t_point	*iter_points;
	t_point	*tmp_points;
	char	**split_line;
	int		line_length;
	int 	x;
	int 	y;

	y = 0;
	fdf->nbr_of_points = 0;
	fdf->points = NULL;
	str = NULL;
	fd = open("./test_maps/42.fdf", O_RDONLY);
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
			iter_points = malloc(line_length * sizeof(t_point));
			if (!iter_points)
				return (perror("iterpoints"), exit(1));
			x = 0;
			while (x < line_length)
			{
				iter_points[fdf->nbr_of_points + x].x = x;
				iter_points[fdf->nbr_of_points + x].y = y;
				iter_points[fdf->nbr_of_points + x].z = ft_atoi_base(
						split_line[x], "0123456789");
				printf("point %d x = %d y = %d z = %d\n", (fdf->nbr_of_points + x), iter_points[fdf->nbr_of_points + x].x, iter_points[fdf->nbr_of_points + x].y, iter_points[fdf->nbr_of_points + x].z);
				x++;
			}
			split_clear(split_line);
			tmp_points = malloc((fdf->nbr_of_points + line_length) * sizeof(t_point));
			if (!tmp_points)
				return (perror("tmp_points"), exit(1));
			if (fdf->points)
			{
				ft_memmove(tmp_points, fdf->points, fdf->nbr_of_points * sizeof(t_point));
				free(fdf->points);
			}
			ft_memmove(tmp_points + fdf->nbr_of_points, iter_points, line_length * sizeof(t_point));
			puts("here");
			free(iter_points);
			fdf->points = tmp_points;
			fdf->nbr_of_points += line_length;
			y += 1;
		}
	}
}

int main()
{
	t_meta_data fdf;

	read_map(&fdf);
	// system("leaks a.out");
	return (0);
}