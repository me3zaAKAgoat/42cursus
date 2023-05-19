/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:21:40 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/18 15:44:25 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stacks	*stacks)
{
	int	min;

	if (is_sorted(stacks->stack_a))
		return ;
	min = ll_is_in(stacks->stack_a, ll_min(stacks->stack_a));
	if (min == 2)
	{
		if (ll_value_atindex(stacks->stack_a, 0)
			> ll_value_atindex(stacks->stack_a, 1))
			return (sa(&stacks->stack_a, 1), rra(&stacks->stack_a, 1));
		else
			return (rra(&stacks->stack_a, 1));
	}
	else if (min == 1)
	{
		if (ll_value_atindex(stacks->stack_a, 0)
			> ll_value_atindex(stacks->stack_a, 2))
			return (ra(&stacks->stack_a, 1));
		else
			return (sa(&stacks->stack_a, 1));
	}
	else
		return (sa(&stacks->stack_a, 1), ra(&stacks->stack_a, 1));
}

void	sort_5(t_stacks	*stacks)
{
	if (is_sorted(stacks->stack_a))
		return ;
	pb(&stacks->stack_a, &stacks->stack_b, 1);
	pb(&stacks->stack_a, &stacks->stack_b, 1);
	sort_3(stacks);
	best_move_to_a(stacks);
	best_move_to_a(stacks);
	smallest_to_top(&stacks->stack_a, ra, rra);
}
