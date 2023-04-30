/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fill_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:16:32 by echoukri          #+#    #+#             */
/*   Updated: 2023/04/30 19:48:03 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*lst_fill_int(int	length, int value)
{
	int		i;
	t_node	*head;

	if (length == 0)
		return (NULL);
	i = 1;
	head = lst_new(value);
	while (i < length)
	{
		lst_last(head)->next = lst_new(value);
		i++;
	}
	return (head);
}