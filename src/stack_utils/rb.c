/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:59 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/02 19:07:53 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rb(t_node	**stack_b_p)
{
	int	value_to_bottom;
	int	value_to_top;

	if (ll_size(*stack_b_p) == 1)
		return ;
	else if (ll_size(*stack_b_p) == 2)
	{
		sb(stack_b_p);
		return ;
	}
	value_to_bottom = ll_shift(stack_b_p);
	value_to_top = ll_pop(*stack_b_p);
	ll_unshift(stack_b_p, ll_new(value_to_top));
	ll_push(stack_b_p, ll_new(value_to_bottom));
}
