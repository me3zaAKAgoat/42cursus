/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:30:01 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/03 22:06:23 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_meta	*meta)
{
	int	value_to_bottom;
	int size;

	size = ll_size(meta->stack_b);
	if (size != 1)
	{
		if (size == 2)
			sb(meta);
		else
		{
			value_to_bottom = ll_shift(&meta->stack_b);
			ll_push(&meta->stack_b, ll_new(value_to_bottom));
			ll_last(meta->stack_b)->next = NULL;
		}
	}	
}
