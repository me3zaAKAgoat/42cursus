/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:16:34 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/05 18:21:51 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	ll_min(t_node	*head)
{
	int		min;
	t_node	*iterator;

	iterator = head;
	min = iterator->value;
	iterator = iterator->next;
	while (iterator)
	{
		if (iterator->value < min)
			min = iterator->value;
		iterator = iterator->next;
	}
	return (min);
}
