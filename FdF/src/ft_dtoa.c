/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:55:41 by echoukri          #+#    #+#             */
/*   Updated: 2023/03/02 23:36:05 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	whole_part(int whole, char *final_str, int i)
{
	while (whole > 0)
	{
		final_str[i++] = (whole % 10) + '0';
		whole /= 10;
	}
	return (i);
}

int	decimal_part(double fraction, char *final_str, int i, int precision)
{
	int		digit;

	while (precision-- > 0)
	{
		fraction *= 10;
		digit = (int) fraction;
		final_str[i++] = digit + '0';
		fraction -= digit;
	}
	return (i);
}

char	*ft_dtoa(double num, int precision)
{
	char	*str;
	double	fraction;
	int		i;

	str = malloc(50 * sizeof(char));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
		i = 1;
	}
	else
		i = 0;
	fraction = num - ((int) num);
	if ((!(int) num))
		str[i++] = '0';
	else
		i = whole_part(num, str, i);
	str[i++] = '.';
	i = decimal_part(fraction, str, i, precision);
	str[i] = '\0';
	return (str);
}
