/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:24:43 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/01 01:24:47 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ll_push(t_node **p_head, t_node *new)
{
	if (*p_head)
		ll_last(*p_head)->next = new;
	else
		*p_head = new;
}
