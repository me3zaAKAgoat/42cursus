/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:30:01 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/04 15:48:17 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_meta	*meta)
{
	int	value_to_top;
	int	size;

	size = ll_size(meta->stack_b);
	if (size != 1)
	{
		if (size == 2)
			sb(meta);
		else
		{
			value_to_top = ll_pop(meta->stack_b);
			ll_atindex(meta->stack_b, size - 2)->next = NULL;
			ll_unshift(&meta->stack_b, ll_new(value_to_top));
		}
	}	
}
