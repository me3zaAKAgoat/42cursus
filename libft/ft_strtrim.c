/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:42:25 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/28 11:23:49 by echoukri         ###   ########.fr       */
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

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1)-1;
	while (s1[start] && in_set(s1[start], set))
		start++;
	while (end >= 0 && in_set(s1[end], set))
		end--;
	if (end < 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		*ptr = '\0';
		return (ptr);
	}
	ptr = ft_substr(s1, start, end - start + 1);
	return (ptr);
}
