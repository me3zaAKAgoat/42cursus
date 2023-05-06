/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:30:01 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/06 02:00:44 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_node	**stack_b)
{
	int	value_to_top;
	int	size;

	size = ll_size(*stack_b);
	if (size != 1)
	{
		if (size == 2)
		{
			sb(stack_b);
			printf("sb\n");
			return ;
		}
		else
		{
			value_to_top = ll_pop(*stack_b);
			ll_atindex(*stack_b, size - 2)->next = NULL;
			ll_unshift(stack_b, ll_new(value_to_top));
		}
	}	
	printf("rb\n");
}
