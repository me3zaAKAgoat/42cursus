/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:08:35 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/07 20:10:15 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ll_print(t_node	*head)
{
	t_node	*iterator;

	iterator = head;
	while (iterator)
	{
		printf("%d ", iterator->value);
		iterator = iterator->next;
	}
	printf("(null)\n");
}

int	main(int ac, char **av)
{
	t_meta	meta;
	t_node	*lis;

	meta.stack_a = parse_input(ac, av);
	meta.stack_b = NULL;
	lis = longest_increasing_subsquence(meta.stack_a);
	move_non_lis(&meta, lis);
	while (meta.stack_b)
		best_move_to_a(&meta);
	smallest_to_top(&meta.stack_a, ra, rra);
	ll_clear(&lis);
	ll_clear(&meta.stack_a);
	ll_clear(&meta.stack_b);
	exit(0);
}
