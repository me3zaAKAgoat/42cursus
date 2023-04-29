/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:19:47 by echoukri          #+#    #+#             */
/*   Updated: 2023/04/29 16:54:42 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_lstiter(t_node	*lst, void (*f)(void	*))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
