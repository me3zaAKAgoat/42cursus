/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trsh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:15:08 by echoukri          #+#    #+#             */
/*   Updated: 2022/12/28 05:31:26 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

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

int main(int argc, char *argv[], char *envp[])
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
