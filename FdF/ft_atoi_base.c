/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:10:00 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/26 18:10:10 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_base_valid(char *str)
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
		if (str[j] == '-' || str[j] == '+' || str[j] == 32 || \
				(9 <= str[j] && str[j] <= 13))
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

int	skip_ws(int i, char *str)
{
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	ft_atoi(char *str, char *base)
{
	int	i;
	int	return_number;
	int	sign;
	int	index;

	return_number = 0;
	sign = 1;
	if (!is_base_valid(base))
		return (0);
	i = skip_ws(0, str);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (base[0] <= str[i] && str[i] <= base[ft_strlen(base) - 1])
	{
		index = 0;
		while (base[index] != str[i])
			index++;
		return_number = return_number * ft_strlen(base) + index;
		i++;
	}
	return (sign * return_number);
}