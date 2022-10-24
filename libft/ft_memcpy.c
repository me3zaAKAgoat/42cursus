/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:12:48 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/24 18:47:11 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		index;
	unsigned char		*dstp;
	const unsigned char	*srcp;

	dstp = dst;
	srcp = src;
	if (!(dst == 0 && src == 0))
	{
		index = 0;
		while (index < n)
		{
			*(dstp + index) = *(srcp + index);
			index++;
		}
	}
	return (dst);
}
