/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:24:56 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/21 20:52:45 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned int	index;

	ptr = (unsigned char *)b;
	index = 0;
	while (index < len)
	{
		*(ptr + index) = (unsigned char)c;
		index++;
	}
	return (ptr);
}
