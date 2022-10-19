/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:54:23 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/19 01:07:36 by echoukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
