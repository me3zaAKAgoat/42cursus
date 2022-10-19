/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:59:07 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/19 01:09:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	char const	*s_start;

	ptr = malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	s_start = s + start;
	ft_strlcpy(ptr, s_start, len + 1);
	return (ptr);
}

// int main()
// {
//     printf("%s\n", ft_substr("KOGMAWF??", 3, 3));
//     exit(0);
// }