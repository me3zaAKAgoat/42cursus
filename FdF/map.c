/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:32:34 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/26 19:03:15 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	if (!dst && !src)
		return (NULL);
	index = 0;
	while (index < n)
	{
		*((char *)dst + index) = *((const char *)src + index);
		index++;
	}
	return (dst);
}

void	read_map(t_meta_data *fdf)
{
	int	fd;
	char *str;
	t_point	*points;
	char **split_line;
	int line_length;
	int x;
	int y;
	
	y = 0;
	fd = open("./test_maps/42.fdf", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL) break;
		else
		{
			y = 
			split_line = ft_split(str, ' ');
			free(str);
			line_length = 0;
			while (split_line[line_length]) line_length++;
			points = malloc(line_length * sizeof(t_point));
			x = 0;
			while (x < line_length)
			{
				points[x].x = x;
				points[x].x = x;
				points[x].x = x;
				x++;
			}
			ft_memcpy()
		}
	}
}

int main()
{
	read_map();
	return (0);
}