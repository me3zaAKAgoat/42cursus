/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:41:06 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/19 11:29:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *haystack, char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (needle[0] == '\0')
		return (haystack);
	while (haystack[i])
	{
		k = i;
		while (haystack[k++] == needle[j++])
		{
			if (!needle[j])
				return (haystack + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}