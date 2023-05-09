/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:15:29 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/09 20:16:43 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node	**stack_a, t_node	**stack_b, int should_print)
{
	int	value_to_push;

	value_to_push = ll_shift(stack_a);
	ll_unshift(stack_b, ll_new(value_to_push));
	if (should_print)
		printf("pb\n");
}
