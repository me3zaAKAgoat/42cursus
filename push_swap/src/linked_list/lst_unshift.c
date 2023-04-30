/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:25:54 by echoukri          #+#    #+#             */
/*   Updated: 2023/04/30 23:26:01 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "linked_list.h"

void	lst_unshift(t_node **p_head, t_node *new)
{
	new->next = *p_head;
	*p_head = new;
}
