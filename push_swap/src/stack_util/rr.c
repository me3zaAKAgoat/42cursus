/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:41:43 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/09 21:42:01 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_node	**stack_a, t_node	**stack_b, int should_print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (should_print)
		write(1, "rr\n", ft_strlen("rr\n"));
}
