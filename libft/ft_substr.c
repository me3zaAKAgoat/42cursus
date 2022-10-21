/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:59:07 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/19 01:09:00 by echoukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;

	ptr = malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr,  s + start, len + 1);
	return (ptr);
}