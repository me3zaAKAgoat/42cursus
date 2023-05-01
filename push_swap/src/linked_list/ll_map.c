/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:24:21 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/01 01:24:21 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*ll_map(t_node	*lst, int (f)(void	*))
{
	t_node	*head;
	t_node	*new;

	head = NULL;
	while (lst)
	{
		new = ll_new(f(&lst->value));
		if (!new)
		{
			ll_clear(&head);
			return (NULL);
		}
		ll_push(&head, new);
		lst = lst->next;
	}
	return (head);
}
