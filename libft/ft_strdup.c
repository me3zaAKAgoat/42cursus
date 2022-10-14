/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:49:22 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/14 13:12:40 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strdup(char *src)
{
	char	*ptr;
	int i;

	ptr = malloc(sizeof(char) * (ft_strlen(src) + 1));
    if (!ptr)
        return (NULL);
	i = 0;
	while (i < ft_strlen(src))
	{
		*(ptr + i) = src[i];
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
