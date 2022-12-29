/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:51:18 by echoukri          #+#    #+#             */
/*   Updated: 2022/12/29 06:26:08 by echoukri         ###   ########.fr       */
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
			return (paths);
		}
		envp++;
	}
	return (0);
}
