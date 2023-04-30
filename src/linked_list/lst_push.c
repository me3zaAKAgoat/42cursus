/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:07:30 by echoukri          #+#    #+#             */
/*   Updated: 2023/04/29 16:54:42 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	lst_push(t_node **p_head, t_node	*new)
{
	if (*p_head)
		lst_last(*p_head)->next = new;
	else
		*p_head = new;
}
