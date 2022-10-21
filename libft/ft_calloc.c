/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:54:23 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/21 20:49:54 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* it wouldnt make sense to give malloc a size that is bigger than
the maximum of size_t and that is SIZE_MAX */
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	unsigned long	index;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	index = 0;
	while (index < count * size)
	{
		ptr[index] = 0;
		index++;
	}
	return (ptr);
}
