/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:41:48 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/02 19:05:41 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node	**stack_a_p)
{
	int	tmp;

	if (ll_size(*stack_a_p) < 2)
		return ;
	tmp = ll_atindex(*stack_a_p, 0)->value;
	ll_atindex(*stack_a_p, 0)->value = ll_atindex(*stack_a_p, 1)->value;
	ll_atindex(*stack_a_p, 1)->value = tmp;
}

