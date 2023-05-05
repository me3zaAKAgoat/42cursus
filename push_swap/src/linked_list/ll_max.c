/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:16:34 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/05 18:21:47 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	ll_max(t_node	*head)
{
	int		max;
	t_node	*iterator;

	iterator = head;
	max = iterator->value;
	iterator = iterator->next;
	while (iterator)
	{
		if (iterator->value > max)
			max = iterator->value;
		iterator = iterator->next;
	}
	return (max);
}
