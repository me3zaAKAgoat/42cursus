/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:40:49 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/01 18:49:47 by echoukri         ###   ########.fr       */
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

char *ft_dtoa(double num, int precision) {
	char *str;
	int whole;
	double fraction;
	int i;
	int digit;

	str = malloc(50 * sizeof(char));
	if (!str)
		return (NULL);
	if (num < 0) {
		num = -num;
		str[0] = '-';
		i = 1;
	} else 
		i = 0;
	whole = (int) num;
	fraction = num - whole;
	if (whole == 0) {
		str[i++] = '0';
	} else {
		while (whole > 0) {
			str[i++] = (whole % 10) + '0';
			whole /= 10;
		}
	}
	str[i++] = '.';
	while (precision-- > 0) {
		fraction *= 10;
		digit = (int) fraction;
		str[i++] = digit + '0';
		fraction -= digit;
	}
	str[i] = '\0';
	return str;
}

void	draw_controls(t_meta_data *fdf)

{
	int	i;

	i += HEIGHT / 63;
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xf0453c, "CONTROLS");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "MOVE UP: W");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "MOVE RIGHT: D");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "MOVE DOWN: S");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "MOVE LEFT: A");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "ROTATE: ARROW KEYS");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "RESET: ENTER");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "QUIT: ESCAPE");
}

void	draw_menu_angles(t_meta_data *fdf, int i)
{
	char	*str;

	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "ALPHA: ");
	str = ft_dtoa(fdf->alpha, 2);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10,
		(i * 30), 0x30f21b, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "BETA : ");
	str = ft_dtoa(-fdf->beta, 2);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10,
		(i * 30), 0x30f21b, str);
	free(str);
}

void	draw_menu(t_meta_data *fdf)
{
	int		i;
	char	*str;

	i = 0;
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xf0453c, "COORDINATES");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "X    : ");
	str = ft_itoa(fdf->x_translation);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10,
		(i * 30), 0x30f21b, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "Y    : ");
	str = ft_itoa(fdf->y_translation);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10,
		(i * 30), 0x30f21b, str);
	free(str);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 20 + 10,
		(++i * 30), 0xFFFFFF, "ZOOM : ");
	str = ft_itoa(fdf->plane_scale_factor);
	mlx_string_put(fdf->mlx, fdf->mlx_win, 80 + 10,
		(i * 30), 0x30f21b, str);
	free(str);
	draw_menu_angles(fdf, i);
	draw_controls(fdf);
}
