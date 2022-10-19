/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:15:06 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/19 00:45:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int index;
	char ci;

	ci = (char)c;
	index = 0;
	if (s[index] == ci)
		return ((char *)(s) + index);
	while (s[index])
	{
		if (s[index + 1] == ci)
			return ((char *)(s) + index + 1);
		index++;
	}
	return (NULL);
}
