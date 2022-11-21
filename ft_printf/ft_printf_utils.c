/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:18:55 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/21 15:33:53 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	convert_char(unsigned char c, int *pto_count)
{
	write(1, &c, 1);
	*pto_count += 1;
}

void	convert_str(const char *arg, int *pto_count)
{
	int	index;

	if (arg)
	{
		index = 0;
		while (arg[index])
		{
			write(1, arg + index, 1);
			*pto_count += 1;
			index++;
		}
	}
	else
	{
		write(1, "(null)", 6);
		*pto_count += 6;
	}
}

void	ft_putulong(unsigned long nb, char *base_s, int *pto_count)
{
	unsigned int	base_l;

	base_l = ft_strlen(base_s);
	if (0 <= nb && nb < base_l)
	{
		write(1, &base_s[nb], 1);
		*pto_count += 1;
	}
	else if (nb >= base_l)
	{
		ft_putulong(nb / base_l, base_s, pto_count);
		ft_putulong(nb % base_l, base_s, pto_count);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		*pto_count += 1;
		ft_putulong(-nb, base_s, pto_count);
	}
}

void	ft_putslong(long nb, char *base_s, int *pto_count)
{
	int	base_l;

	base_l = ft_strlen(base_s);
	if (0 <= nb && nb < base_l)
	{
		write(1, &base_s[nb], 1);
		*pto_count += 1;
	}
	else if (nb >= base_l)
	{
		ft_putslong(nb / base_l, base_s, pto_count);
		ft_putslong(nb % base_l, base_s, pto_count);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		*pto_count += 1;
		ft_putslong(-nb, base_s, pto_count);
	}
}
