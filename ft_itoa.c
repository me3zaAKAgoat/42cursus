/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:01:20 by echoukri          #+#    #+#             */
/*   Updated: 2023/02/25 14:05:55 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>

// static int	get_nbr_len(int n)
// {
// 	int	len;

// 	len = 1;
// 	while (n / 10 != 0)
// 	{
// 		n /= 10;
// 		len++;
// 	}
// 	return (len);
// }

// static char	*fill_str(int n, int sign, int len)
// {
// 	char	*str;
// 	int		i;

// 	str = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	str[len] = '\0';
// 	i = len - 1;
// 	while (n / 10 != 0)
// 	{
// 		str[i] = (n % 10) * sign + '0';
// 		n /= 10;
// 		i--;
// 	}
// 	str[i] = n * sign + '0';
// 	if (sign == -1)
// 		str[0] = '-';
// 	return (str);
// }

// char		*ft_itoa(int n)
// {
// 	char	*str;
// 	int		sign;
// 	int		len;

// 	sign = (n < 0) ? -1 : 1;
// 	len = get_nbr_len(n) + ((sign == -1) ? 1 : 0);
// 	str = fill_str(n, sign, len);
// 	return (str);
// }

#include "fdf.h"

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
