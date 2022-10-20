/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:20 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/20 19:03:46 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char * dst, const char * src, size_t size)
{
	unsigned int	index;
	size_t			srcl;
	size_t			dstl;


	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	index = 0;
	if (srcl < size)
	{
		ft_memcpy(dst, src, srcl+1);
	}
	else if (size != 0)
	{
		ft_memcpy(dst, src, size-1);
		dst[size-1] = '\0';
	}
	return (srcl);
}
