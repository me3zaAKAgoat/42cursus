/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 00:30:36 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/05 23:48:01 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	ll_shift(t_node **head_p)
{
	t_node	*head;
	int		value_removed;

	head = *head_p;
	value_removed = head->value;
	*head_p = head->next;
	ll_del_one(head);
	return (value_removed);
}
