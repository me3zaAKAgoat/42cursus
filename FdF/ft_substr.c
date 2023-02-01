/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:59:07 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/31 16:25:38 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
malloc should only allcoate the needed space
in the case where len is more than can be cut from the initial string
one should not allocate the full len but only what can be cut

thus the formula (len <= slen - start) * len
				+ (slen - start) * (slen - start < len) + 1
*/


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	if (!dst && !src)
		return (NULL);
	index = 0;
	while (index < n)
	{
		*((char *)dst + index) = *((const char *)src + index);
		index++;
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			srcl;

	srcl = ft_strlen(src);
	if (srcl < size)
		ft_memcpy(dst, src, srcl + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srcl);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		*ptr = '\0';
	}
	else
	{
		ptr = malloc((len <= slen - start) * len
				+ (slen - start) * (slen - start < len) + 1);
		if (!ptr)
			return (NULL);
		else
			ft_strlcpy(ptr, s + start, (len <= slen - start) * len
				+ (slen - start) * (slen - start < len) + 1);
	}
	return (ptr);
}
