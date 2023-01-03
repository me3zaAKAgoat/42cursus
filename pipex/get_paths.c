/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:51:18 by echoukri          #+#    #+#             */
/*   Updated: 2023/01/03 14:29:33 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// check for possibilites of failure
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
			split_clear(tmp);
			return (paths);
		}
		envp++;
	}
	return (NULL);
}
