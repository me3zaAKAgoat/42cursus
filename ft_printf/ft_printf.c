/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:44:20 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/15 17:15:06 by echoukri         ###   ########.fr       */
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
	ft_putnbr((unsigned long) arg, "0123456789abcdef");
}

int	ft_printf(const char *s, ...)
{
	size_t	index;
	va_list	args;

	index = 0;
	va_start(args, s);
	while (s[index])
	{
		if (s[index] == '%')
		{
			index++;
			if (s[index] == 'c')
				convert_char(va_arg(args, int));
			if (s[index] == 's')
				convert_str(va_arg(args, char *));
			if (s[index] == 'p')
				convert_ptr(va_arg(args, void *));
		}
		else
			write(1, &s[index], 1);
		index++;
	}
	va_end(args);
	return (0);
}

int	main()
{
	char *ptr = "trollege";

	printf("character: %c pointer in hexa: %p string pointed to: %s", 'X', ptr, ptr);
	ft_printf("character: %c pointer in hexa: %p string pointed to: %s", 'X', ptr, ptr);
	return 0;
}
