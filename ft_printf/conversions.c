/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:21:40 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/16 14:22:56 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_char(char arg)
{
	char	c_buff;

	c_buff = arg;
	write(1, &c_buff, 1);
}

void	convert_str(char *arg)
{
	int	index;

	index = 0;
	while (arg[index])
	{
		write(1, arg + index, 1);
		index++;
	}
}

void	convert_ptr(void	*arg)
{
	write(1, "0x", 2);
	ft_putulong((unsigned long) arg, "0123456789abcdef");
}

void	convert_decimal(int arg)
{
	ft_putdecimal(arg, "0123456789");
}

void	convert_udecimal(unsigned int arg)
{
	ft_putulong((unsigned int) arg, "0123456789");
}
