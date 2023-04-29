/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:07:30 by echoukri          #+#    #+#             */
/*   Updated: 2023/04/29 00:35:10 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_lstadd_back(t_list_item **p_head, t_list_item  *new)
{
	if (*p_head)
		ft_lstlast(*p_head)->next = new;
	else
		*p_head = new;
}
