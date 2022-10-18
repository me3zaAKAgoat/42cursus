/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:15:06 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/18 16:41:31 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strchr(const char *s, int c)
{
	int index;
	char ci;

	ci = (char)c;
	index = 0;
	if (s[index] == ci)
		return (s + index);
	while (s[index])
	{
		if (s[index + 1] == ci)
			return (s + index + 1);
		index++;
	}
	return (NULL);
}