/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:12:33 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/24 19:21:12 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	return_number;
	int	i;
	int	sign;

	i = 0;
	return_number = 0;
	sign = 1;
	while ((str[i] <= 13 && 9 <= str[i]) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
		return_number = return_number * 10 + (str[i++] - 48);
	return (sign * return_number);
}

int main()
{
	printf("atoi: %d\n", atoi("-2147483648"));
	printf("ft_atoi: %d\n", ft_atoi("-2147483648"));
	return 0;
}