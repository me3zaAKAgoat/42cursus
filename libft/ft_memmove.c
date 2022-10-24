/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:47:38 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/24 17:18:34 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
knowing that we cannot allocate heap memory nor 
have variable size arrays to make a temporary array
to hold the bytes to accomodate 
for the event the two buffers overlap
the implemented algorithm will be such as:

zeadmchaydirlbech9oli

src = zeadmchaydirlbech9oli
dst = lbech9oli

*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tempp;
	unsigned int		index;

	tempp = malloc(sizeof(unsigned char) * len);
	if (tempp == NULL)
		return (NULL);
	else
	{
		index = 0;
		while (index < len)
		{
			*(tempp + index) = *((const unsigned char *)src + index);
			index++;
		}
		index = 0;
		while (index < len)
		{
			*((unsigned char *)dst + index) = *(tempp + index);
			index++;
		}
		free(tempp);
	}
	return (dst);
}
