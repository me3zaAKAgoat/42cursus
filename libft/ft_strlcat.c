/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:21:20 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/18 16:38:08 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	unsigned int i;
	unsigned int j;
	unsigned int dstl;
	unsigned int srcl;

	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	i = 0;
	j = 0;
	if (size < dstl)
		return (size + srcl);
	else
	{
		while (dst[i])
			i++;
		while (src[j] && i <= size - 2)
			dst[i++] = src[j++];
		dst[i + 1] = '\0';
	}
	return (dstl + srcl);
}