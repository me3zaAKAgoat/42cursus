/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:40:49 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/04 15:27:11 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	ci;

	ci = (char)c;
	index = 0;
	if (s[index] == ci)
		return ((char *)(s) + index);
	while (s[index])
	{
		if (s[index + 1] == ci)
			return ((char *)(s) + index + 1);
		index++;
	}
	return (NULL);
}

void	perr_exit(char *msg)
{
	perror(msg);
	exit(1);
}

int	count_words(char const *s, char c)
{
	int	count_of_c;
	int	index;

	count_of_c = 1;
	index = 0;
	while (s[index])
	{	
		if (s[index] != c)
		{
			while (s[index] != c && s[index])
				index++;
			count_of_c++;
		}
		else
			index++;
	}
	return (count_of_c);
}

void	cleanup_meta_data(t_meta_data *fdf)
{
	free(fdf->y_lengths_arr);
	free(fdf->points);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	mlx_destroy_window(fdf->mlx, fdf->mlx_win);
}
