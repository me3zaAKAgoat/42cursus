/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:16:19 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/28 17:05:38 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstclear(t_list	**lst, void (*del)(void	*))
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			if (del)
				del((*lst)->content);
			tmp = (*lst)->next;
			free(*lst);
			(*lst) = tmp;
		}
		*lst = NULL;
	}
}
