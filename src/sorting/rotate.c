/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:19:32 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/07 15:28:29 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_needed_to_top(t_node *stack_x, int value)
{
	int	moves;
	int	index;

	index = ll_is_in(stack_x, value);
	if (index > (ll_size(stack_x) - 1) / 2)
		moves = index - (ll_size(stack_x));
	else
		moves = index;
	return (moves);
}

void	rotate_n_times(t_node **stack_x, int moves,
	void (rx)(t_node **stack_x, int should_print),
	void (rrx)(t_node	**stack_x, int should_print))
{
	if (moves < 0)
		while (moves++)
			rrx(stack_x, 1);
	else if (moves > 0)
		while (moves--)
			rx(stack_x, 1);
}

void	rotate_to_top(t_node **stack_x, int value,
	void (rx)(t_node **stack_x, int should_print),
	void (rrx)(t_node **stack_x, int should_print))
{
	int	n;

	n = moves_needed_to_top(*stack_x, value);
	rotate_n_times(stack_x, n, rx, rrx);
}

void	smallest_to_top(t_node **stack_x, void (rx)(t_node **stack_x,
	int should_print), void (rrx)(t_node **stack_x, int should_print))
{
	int		min;

	min = ll_min(*stack_x);
	rotate_to_top(stack_x, min, rx, rrx);
}
