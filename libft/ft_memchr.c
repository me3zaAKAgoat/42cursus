/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:59:07 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/25 19:53:12 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	index;
	unsigned char	ci;
	unsigned char	*converted_s;

	ci = c;
	converted_s = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (converted_s[index] == ci)
			return (converted_s + index);
		index++;
	}
	return (NULL);
}
