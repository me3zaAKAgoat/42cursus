/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:41:43 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/09 21:43:03 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_node	**stack_a, t_node	**stack_b, int should_print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (should_print)
		write(1, "rrr\n", ft_strlen("rrr\n"));
}
