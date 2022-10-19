/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:32:16 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/19 00:49:07 by echoukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int index;
	char ci;
	unsigned int sl;

	sl = ft_strlen(s);
	ci = (char)c;
	index = 0;
	if (s[sl - index] == ci)
		return ((char *)(s) + sl - index);
	while (s[index])
	{
		if (s[sl - index - 1] == ci)
			return ((char *)(s) - index - 1);
		index++;
	}
	return (NULL);
}