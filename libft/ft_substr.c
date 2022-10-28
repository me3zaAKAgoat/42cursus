/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:59:07 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/28 16:31:06 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
malloc should only allcoate the needed space
in the case where len is more than can be cut from the initial string
one should not allocate the full len but only what can be cut

thus the formula (len <= slen - start) * len
				+ (slen - start) * (slen - start < len) + 1
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		*ptr = '\0';
	}
	else
	{
		ptr = malloc((len <= slen - start) * len
				+ (slen - start) * (slen - start < len) + 1);
		if (!ptr)
			return (NULL);
		else
			ft_strlcpy(ptr, s + start, (len <= slen - start) * len
				+ (slen - start) * (slen - start < len) + 1);
	}
	return (ptr);
}
