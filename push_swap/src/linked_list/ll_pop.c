/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 00:30:36 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/02 17:46:48 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	ll_pop(t_node *head)
{
	t_node	*node;
	int		value_removed;
	int		size;

	size = ll_size(head);
	node = ll_last(head);
	value_removed = node->value;
	ll_del_one(node);
	ll_atindex(head, size - 2)->next = NULL;
	return (value_removed);
}
