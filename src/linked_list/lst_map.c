/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:01:15 by echoukri          #+#    #+#             */
/*   Updated: 2023/04/30 19:45:41 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*lst_map(t_node	*lst,
	int	(*f)(void *))
{
	t_node	*head;
	t_node	*new;

	head = NULL;
	while (lst)
	{
		new = lst_new(f(&lst->value));
		if (!new)
		{
			lst_clear(&head);
			return (NULL);
		}
		lst_push(&head, new);
		lst = lst->next;
	}
	return (head);
}
