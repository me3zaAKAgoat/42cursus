/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:41:48 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/02 23:45:28 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_meta	*meta)
{
	int	tmp;

	if (ll_size(meta->stack_b) < 2)
		return ;
	tmp = ll_atindex(meta->stack_b, 0)->value;
	ll_atindex(meta->stack_b, 0)->value = ll_atindex(meta->stack_b, 1)->value;
	ll_atindex(meta->stack_b, 1)->value = tmp;
}
