/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 00:30:36 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/02 02:02:05 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	ll_pop(t_node *head)
{
	t_node	*node;
	int		value_removed;

	node = ll_last(head);
	value_removed = node->value;
	ll_del_one(node);
	return (value_removed);
}
