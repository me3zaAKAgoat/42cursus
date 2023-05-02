/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:41:48 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/02 18:45:47 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node	**stack_b_p)
{
	int	a;
	int	b;

	a = ll_shift(stack_b_p);
	b = ll_shift(stack_b_p);
	ll_unshift(stack_b_p, ll_new(a));
	ll_unshift(stack_b_p, ll_new(b));
}
