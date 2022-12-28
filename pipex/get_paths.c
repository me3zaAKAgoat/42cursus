/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pathS.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:51:18 by echoukri          #+#    #+#             */
/*   Updated: 2022/12/28 02:43:31 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	while (haystack[i] && i < len)
	{
		k = i;
		while (haystack[k++] == needle[j++])
		{
			if (k > len)
				return (NULL);
			if (!needle[j])
				return ((char *)(haystack) + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}

char	**get_paths(char	*envp[])
{
	char	**paths;
	char	**tmp;

	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH", ft_strlen(*envp)))
		{
			tmp = ft_split(*envp, '=');
			paths = ft_split(tmp[1], ':');
			while (*paths)
			{
				printf("%s\n", *paths);
				paths++;
			}
			return (0);
		}
		envp++;
	}
	return (0);
}
