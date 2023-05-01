/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_fill_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:23:11 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/01 01:26:30 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*ll_fill_int(int length, int value)
{
	int		i;
	t_node	*head;

	if (length == 0)
		return (NULL);
	i = 1;
	head = ll_new(value);
	while (i < length)
	{
		ll_last(head)->next = ll_new(value);
		i++;
	}
	return (head);
}
