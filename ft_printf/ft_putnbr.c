/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:18:55 by echoukri          #+#    #+#             */
/*   Updated: 2022/11/15 17:14:31 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	is_base_valid(char *str)
{
	int	j;
	int	k;
	int	count;

	j = 0;
	if (ft_strlen(str) <= 1)
		return (0);
	while (str[j])
	{
		count = 0;
		k = 0;
		if (str[j] == '-' || str[j] == '+')
			return (0);
		while (str[k])
		{
			if (str[k++] == str[j])
				count += 1;
		}
		if (count >= 2)
			return (0);
		j++;
	}
	return (1);
}

void	ft_putnbr(unsigned long nb, char *str)
{
	int	base;

	base = ft_strlen(str);
	if (!is_base_valid(str))
		return ;
	else if (nb == -2147483648)
	{
		ft_putnbr(nb / base, str);
		ft_putnbr(-(nb % base), str);
	}
	else if (0 <= nb && nb < base)
		write(1, &str[nb], 1);
	else if (nb >= base)
	{
		ft_putnbr(nb / base, str);
		ft_putnbr(nb % base, str);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb, str);
	}
}
