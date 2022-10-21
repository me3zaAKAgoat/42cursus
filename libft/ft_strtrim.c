/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:42:25 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/21 20:49:26 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	int	index;

	index = 0;
	while (set[index])
	{
		if (c == set[index])
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	end = ft_strlen(s1)-1;
	start = 0;
	while (s1[start] && in_set(s1[start], set))
	start++;
	if (start - 1 == end)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	while (end >= 0 && in_set(s1[end], set))
		end--;
	ptr = ft_substr(s1, start, end - start + 1);
	return (ptr);
}
