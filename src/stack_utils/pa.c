/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:15:29 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/06 00:39:36 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node	**stack_a, t_node	**stack_b)
{
	int	value_to_push;

	value_to_push = ll_shift(stack_b);
	ll_unshift(stack_a, ll_new(value_to_push));
}
