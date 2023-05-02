/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:30:01 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/02 23:33:37 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_meta	*meta)
{
	int	value_to_top;
	int	value_to_bottom;

	if (ll_size(meta->stack_a) == 1)
		return ;
	else if (ll_size(meta->stack_a) == 2)
	{
		sa(meta);
		return ;
	}
	value_to_bottom = ll_shift(&meta->stack_a);
	value_to_top = ll_pop(meta->stack_a);
	ll_unshift(&meta->stack_a, ll_new(value_to_top));
	ll_push(&meta->stack_a, ll_new(value_to_bottom));
}
