/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:14:56 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/21 20:49:51 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	index;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		*(ptr + index) = '\0';
		index++;
	}
}
