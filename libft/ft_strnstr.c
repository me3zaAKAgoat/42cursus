/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:26:59 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/19 17:26:59 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	while (haystack[i] && i < len)
	{
		k = i;
		while (haystack[k++] == needle[j++])
		{
			if (k > len)
				return (NULL);
			if (!needle[j])
				return ((char *)(haystack) + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
