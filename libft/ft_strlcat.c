/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:21:20 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/24 21:22:08 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size < dstlen
// size > dstlen
// dst has enough room
// dst dosent have enough room
// srcl = 0
// dstl = 0

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	char *d = dst;
// 	const char *s = src;
// 	size_t n = size;
// 	size_t dlen;

// 	/* Find the end of dst and adjust bytes left but don't go past end */
// 	while (n-- != 0 && *d != '\0')
// 		d++;
// 	dlen = d - dst;
// 	n = size - dlen;

// 	if (n == 0)
// 		return(dlen + ft_strlen(s));
// 	while (*s != '\0') {
// 		if (n != 1) {
// 			*d++ = *s;
// 			n--;
// 		}
// 		s++;
// 	}
// 	*d = '\0';

// 	return(dlen + (s - src));	/* count does not include NUL */
// }
// {
	// unsigned int	i;
	// unsigned int	j;
	// unsigned int	dstl;
	// unsigned int	srcl;

	// dstl = ft_strlen(dst);
	// srcl = ft_strlen(src);
	// i = 0;
	// j = 0;
	// if (size == 0)
	// 	return (srcl);
	// if (size <= dstl)
	// 	return (dstl + srcl);
	// else
	// {	
	// 	while (dst[i])
	// 		i++;
	// 	while (src[j] && i <= size - 2)
	// 		dst[i++] = src[j++];
	// 	dst[i + 1] = '\0';
	// }
	// return (dstl + srcl);
// }
