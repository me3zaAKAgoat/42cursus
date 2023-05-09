/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:53:40 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/09 01:03:01 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;
	t_node		*lis;
	
	stacks.stack_a = parse_input(ac, av);
	
	lis = longest_increasing_subsquence(stacks.stack_a);
	if (ll_size(lis) == ll_size(stacks.stack_a))
		printf("OK\n");
	else
		printf("KO");
	exit(0);
}