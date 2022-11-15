/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:18:55 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/15 21:01:01 by echoukri         ###   ########.fr       */
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

void	ft_putdecimal(long nb, char *base_s)
{
	int	base_l;

	base_l = ft_strlen(base_s);
	if (0 <= nb && nb < base_l)
		write(1, &base_s[nb], 1);
	else if (nb >= base_l)
	{
		ft_putdecimal(nb / base_l, base_s);
		ft_putdecimal(nb % base_l, base_s);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putdecimal(-nb, base_s);
	}
}
