/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:32:34 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/29 19:27:08 by echoukri         ###   ########.fr       */
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


// void	fill_point_coordinates(t_meta_data *fdf, int line_length)
// {
// 	int	x;

// 	x = 0;
	
// }

void	alloc_for_points(t_meta_data *fdf)
{
	int		fd;
	int		non_spc_nl_count;
	char	*str;

	non_spc_nl_count = 0;
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

void	read_map(t_meta_data *fdf)
{
	int		fd;
	char	*str;
	char	**split_line;
	t_point	point;
	int		line_length;
	int		x;
	int		y;

	y = 0;
	fdf->nbr_of_points = 0;
	fdf->points = NULL;
	str = NULL;
	alloc_for_points(&fdf);
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
			x = 0;
			while (x < line_length)
			{
				// printf("%d\n", fdf->points[fdf->nbr_of_points + x].x);
				point.x = x;
				point.y = y;
				point.z = ft_atoi_base(
						split_line[x], "0123456789");
				fdf->points[fdf->nbr_of_points + x] = point;
				x++;
			}
			split_clear(split_line);
			fdf->nbr_of_points += line_length;
			y += 1;
		}
	}
}

int main()
{
	t_meta_data fdf;
	int i = 0;
	
	read_map(&fdf);
	while (i < fdf.nbr_of_points)
	{
		printf("point %d x = %d y = %d z = %d\n", (i), (fdf.points[i]).x,( fdf.points[i]).y,( fdf.points[i]).z);
		i++;
	}

	// system("leaks a.out");
	return (0);
}