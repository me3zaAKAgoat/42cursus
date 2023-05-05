/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:30:01 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/05 16:01:12 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node	**stack_a)
{
	int	value_to_bottom;
	int	size;

	size = ll_size(*stack_a);
	if (size != 1)
	{
		if (size == 2)
			sa(stack_a);
		else
		{
			value_to_bottom = ll_shift(stack_a);
			ll_push(stack_a, ll_new(value_to_bottom));
			ll_last(*stack_a)->next = NULL;
		}
	}	
}
