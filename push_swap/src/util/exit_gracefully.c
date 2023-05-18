/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_gracefully.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:20:26 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/18 14:20:37 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_gracefully(t_stacks *stacks)
{
	ll_clear(&stacks->stack_a);
	ll_clear(&stacks->stack_b);
	exit(0);
}
