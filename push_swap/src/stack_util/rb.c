/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:30:01 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/16 18:57:12 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_node	**stack_b, int should_print)
{
	int	value_to_bottom;
	int	size;

	size = ll_size(*stack_b);
	if (size > 1)
	{
		if (size == 2)
		{
			sb(stack_b, should_print);
			return ;
		}
		else
		{
			value_to_bottom = ll_shift(stack_b);
			ll_push(stack_b, ll_new(value_to_bottom));
			ll_last(*stack_b)->next = NULL;
		}
	}
	if (should_print)
		write(1, "rb\n", ft_strlen("rb\n"));
}
