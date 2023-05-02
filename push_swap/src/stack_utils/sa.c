/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:41:48 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/02 23:44:59 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_meta	*meta)
{
	int	tmp;

	if (ll_size(meta->stack_a) < 2)
		return ;
	tmp = ll_atindex(meta->stack_a, 0)->value;
	ll_atindex(meta->stack_a, 0)->value = ll_atindex(meta->stack_a, 1)->value;
	ll_atindex(meta->stack_a, 1)->value = tmp;
}

