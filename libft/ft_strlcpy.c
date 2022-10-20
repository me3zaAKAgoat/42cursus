/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:20 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/20 18:29:22 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char * dst, const char * src, size_t size)
{
	unsigned int	index;
	unsigned int	srcl;
	unsigned int	dstl;


	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	index = 0;
	if (size < srcl)
	{
		while (src[index])
		{
			if (index <= size - 2)
			{
				dst[index] = src[index];
				index++;
			}
			else
				break;
		}
	}
	else if (size != 0)
	{
		while (src[index])
		{
			if (index <= size - 2)
			{
				dst[index] = src[index];
				index++;
			}
			else
				break;
		}
		dst[index] = '\0';
	}
	return (srcl);
}
