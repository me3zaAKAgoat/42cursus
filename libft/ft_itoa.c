/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:39:25 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/21 20:50:53 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_putnbr(long int nb, int pos, char *ptr)
{
	if (0 <= nb && nb < 10)
		ptr[pos - 1] = nb + '0';
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10, pos - 1, ptr);
		ft_putnbr(nb % 10, pos, ptr);
	}
	else if (nb < 0)
	{
		ptr[0] = '-';
		ft_putnbr(-nb, pos + 1, ptr);
	}
}

static int	count_digits(int n)
{
	int		n_digits;

	n_digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		n_digits += 1;
	}
	return (n_digits);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		n_digits;

	n_digits = count_digits(n);
	if (n < 0)
	{
		ptr = malloc((n_digits + 2) * sizeof(char));
		if (!ptr)
			return (NULL);
		ptr[n_digits + 1] = '\0';
		ft_putnbr(n, n_digits, ptr);
	}
	else
	{
		ptr = malloc((n_digits + 1) * sizeof(char));
		if (!ptr)
			return (NULL);
		ptr[n_digits] = '\0';
		ft_putnbr(n, n_digits, ptr);
	}
	return (ptr);
}
