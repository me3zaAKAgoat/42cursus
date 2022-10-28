/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:06:17 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/28 14:01:43 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1byte;
	unsigned char	*s2byte;

	s1byte = (unsigned char *)s1;
	s2byte = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1byte[i] == s2byte[i] && i < n - 1)
		i++;
	return (s1byte[i] - s2byte[i]);
}
