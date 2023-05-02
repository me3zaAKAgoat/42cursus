/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:30:01 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/02 18:55:54 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node	**stack_a_p)
{
	int	value_to_bottom;
	int	value_to_top;

	if (ll_size(*stack_a_p) == 1)
		return ;
	else if (ll_size(*stack_a_p) == 2)
		sa(stack_a_p);
	value_to_bottom = ll_shift(stack_a_p);
	value_to_top = ll_pop(*stack_a_p);
	ll_unshift(stack_a_p, ll_new(value_to_top));
	ll_push(stack_a_p, ll_new(value_to_bottom));
}
