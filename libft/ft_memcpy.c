/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:12:48 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/19 19:38:16 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned int	index;
    unsigned char *restrict dstp;
	const unsigned char *restrict srcp;
	
    dstp = dst;
	srcp = src;
	index = 0;
	while (index < n)
	{
		*(dstp + index) = *(srcp + index);
		index++;
	}
	return (dst);
}
