/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:30:01 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/04 15:48:10 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_meta	*meta)
{
	int	value_to_top;
	int	size;

	size = ll_size(meta->stack_a);
	if (size != 1)
	{
		if (size == 2)
			sa(meta);
		else
		{
			value_to_top = ll_pop(meta->stack_a);
			ll_atindex(meta->stack_a, size - 2)->next = NULL;
			ll_unshift(&meta->stack_a, ll_new(value_to_top));
		}
	}	
}
