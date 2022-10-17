/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:20 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/17 17:17:09 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	unsigned int	index;
	int				srcl;

	srcl = ft_strlen(src);
	index = 0;
	if (dstsize)
	{
		while (src[index])
		{
			if (index <= dstsize - 2)
			{
				dst[index] = src[index];
				index++;
			}
			else
				break ;
		}
		dst[index] = '\0';
	}
	return (srcl);
}
