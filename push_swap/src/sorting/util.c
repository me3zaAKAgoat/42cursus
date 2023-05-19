/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:26 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/18 15:52:14 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void	cheesy_swap(t_stacks *stacks)
{
	if (ll_size(stacks->stack_a) >= 2)
	{
		if (ll_value_atindex(stacks->stack_a, 0)
			> ll_value_atindex(stacks->stack_a, 1))
			sa(&stacks->stack_a, 1);
	}
}
