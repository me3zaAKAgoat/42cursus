/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:08:35 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/18 15:52:10 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include <stdio.h>
// void	ll_print(t_node	*head)
// {
// 	t_node	*iterator;

// 	iterator = head;
// 	while (iterator)
// 	{
// 		printf("%d ", iterator->value);
// 		iterator = iterator->next;
// 	}
// 	printf("(null)\n");
// }

int	main(int ac, char **av)
{
	t_stacks	stacks;
	t_node		*lis;

	stacks.stack_a = parse_input(ac, av);
	stacks.stack_b = NULL;
	if (ll_size(stacks.stack_a) == 3)
		sort_3(&stacks);
	if (ll_size(stacks.stack_a) == 5)
		sort_5(&stacks);
	cheesy_swap(&stacks);
	smallest_to_top(&stacks.stack_a, ra, rra);
	lis = longest_increasing_subsquence(stacks.stack_a);
	move_non_lis(&stacks, lis);
	while (stacks.stack_b)
		best_move_to_a(&stacks);
	smallest_to_top(&stacks.stack_a, ra, rra);
	ll_clear(&lis);
	ll_clear(&stacks.stack_a);
	ll_clear(&stacks.stack_b);
	exit(0);
}
