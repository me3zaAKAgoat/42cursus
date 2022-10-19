/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:47:38 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/19 17:38:34 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*srcp;
	unsigned char		*dstp;
	unsigned char		*tempp;
	unsigned int		index;

	srcp = (const unsigned char *)src;
	dstp = (unsigned char *)dst;
	tempp = (unsigned char *)malloc(sizeof(unsigned char) * len);
	if (tempp == NULL)
		return (NULL);
	else
	{
		index = 0;
		while (index < len)
		{
			*(tempp + index) = *(srcp + index);
			index++;
		}
		index = 0;
		while (index < len)
		{
			*(dstp + index) = *(tempp + index);
			index++;
		}
		free(tempp);
	}
	return (dstp);
}