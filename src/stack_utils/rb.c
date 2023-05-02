/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:59 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/02 23:01:40 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rb(t_meta	*meta)
{
	int	value_to_bottom;
	int	value_to_top;

	if (ll_size(meta->stack_b) == 1)
		return ;
	else if (ll_size(meta->stack_b) == 2)
	{
		sb(meta);
		return ;
	}
	value_to_bottom = ll_shift(&meta->stack_b);
	value_to_top = ll_pop(meta->stack_b);
	ll_unshift(&meta->stack_b, ll_new(value_to_top));
	ll_push(&meta->stack_b, ll_new(value_to_bottom));
}
