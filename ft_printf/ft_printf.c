/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:44:20 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/15 21:18:17 by echoukri         ###   ########.fr       */
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

void	conversion_decider(char	format, va_list args)
{
	if (format == 'c')
		convert_char(va_arg(args, int));
	if (format == 's')
		convert_str(va_arg(args, char *));
	if (format == 'p')
		convert_ptr(va_arg(args, void *));
	if (format == 'd' || format == 'i')
		convert_decimal(va_arg(args, int));
	if (format == 'u')
		convert_udecimal(va_arg(args, unsigned int));
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
			conversion_decider(s[index], args);
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
	int		i = -53;
	unsigned int ui = 4294967295;

	printf("character: %c pointer in hexa: %p string pointed to: %s decimal: %d %i unsigned decimal: %u\n", 'X', ptr, ptr, i, i, ui);
	ft_printf("character: %c pointer in hexa: %p string pointed to: %s decimal: %d %i unsigned decimal: %u\n", 'X', ptr, ptr, i, i, ui);
	return 0;
}
