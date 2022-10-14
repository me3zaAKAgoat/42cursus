/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:12:33 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/14 12:17:38 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	return_number;
	int	i;
	int	sign;

	i = 0;
	return_number = 0;
	sign = 1;
	while ((str[i] <= 13 && 9 <= str[i]) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		return_number = return_number * 10 + (str[i++] - 48);
	}
	return (sign * return_number);
}