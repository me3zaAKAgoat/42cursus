/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_atindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:22:44 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/01 01:32:11 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*ll_atindex(t_node *head, int index)
{
	int		i;
	t_node	*current;

	i = 0;
	current = head;
	while (i < index)
	{
		if (current == NULL)
			return (NULL);
		current = current->next;
		i++;
	}
	return (current);
}
