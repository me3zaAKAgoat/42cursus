/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:23:36 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/14 13:25:03 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	concatenate(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int space;
	int i;
	char *ptr;

	i = 0;
	space = 0;
	if (size == 0)
	{
		ptr = malloc(sizeof(char));

	}
	while (i < size)
		space += ft_strlen(strs[i++]);
	space += ft_strlen(sep)*(size - 1);
	ptr = malloc(sizeof(char) * space + 1);
	*ptr = '\0';
	i = 0;
	while (i < size)
	{
		concatenate(ptr, strs[i]);
		if (i < size - 1)
			concatenate(ptr, sep);
		i++;
	}
	return (ptr);
}