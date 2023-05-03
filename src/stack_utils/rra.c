/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:30:01 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/03 22:06:28 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_meta	*meta)
{
	int	value_to_bottom;
	int size;

	size = ll_size(meta->stack_a);
	if (size != 1)
	{
		if (size == 2)
			sa(meta);
		else
		{
			value_to_bottom = ll_shift(&meta->stack_a);
			ll_push(&meta->stack_a, ll_new(value_to_bottom));
			ll_last(meta->stack_a)->next = NULL;
		}
	}	
}
