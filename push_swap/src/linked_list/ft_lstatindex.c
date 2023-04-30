/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstatindex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:32:19 by echoukri          #+#    #+#             */
/*   Updated: 2023/04/30 20:36:38 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*ft_lstatindex(t_node *head, int index)
{
	int		iterator;
	t_node	*current;

	iterator = 0;
	current = head;
	while (iterator < index)
	{
		if (current == NULL)
			return (NULL);
		current = current->next;
		iterator++;
	}
	return (current);
}
