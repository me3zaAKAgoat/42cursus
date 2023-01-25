/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:32:34 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/25 18:00:23 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_map(void)
{
	int	fd;
	char *str;

	fd = open("./test_maps/42.fdf", O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s\n", str);
		str = get_next_line(fd);
	}
}

int main()
{
	read_map();
	return (0);
}