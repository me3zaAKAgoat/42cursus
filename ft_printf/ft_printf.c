/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:44:20 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/29 02:47:51 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conversion_decider(char format, va_list args, int *pto_count)
{
	if (format == 'c')
		convert_char(va_arg(args, int), pto_count);
	else if (format == 's')
		convert_str(va_arg(args, const char *), pto_count);
	else if (format == 'p')
	{
		write(1, "0x", 2);
		*pto_count += 2;
		ft_putulong(va_arg(args, unsigned long), "0123456789abcdef", pto_count);
	}
	else if (format == 'd' || format == 'i')
		ft_putslong(va_arg(args, int), "0123456789", pto_count);
	else if (format == 'u')
		ft_putulong(va_arg(args, unsigned int), "0123456789", pto_count);
	else if (format == 'x')
		ft_putulong(va_arg(args, unsigned int), "0123456789abcdef", pto_count);
	else if (format == 'X')
		ft_putulong(va_arg(args, unsigned int), "0123456789ABCDEF", pto_count);
	else if (format == '%')
	{
		write(1, "%", 1);
		*pto_count += 1;
	}
}

int	ft_printf(const char *s, ...)
{
	size_t	index;
	va_list	args;
	int		charprint_count;

	index = 0;
	charprint_count = 0;
	va_start(args, s);
	while (s[index])
	{
		if (s[index] == '%')
		{
			index++;
			conversion_decider(s[index], args, &charprint_count);
		}
		else
		{
			write(1, &s[index], 1);
			charprint_count += 1;
		}
		index++;
	}
	va_end(args);
	return (charprint_count);
}
