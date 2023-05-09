/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:53:40 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/09 21:45:27 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	execute_instruction(t_stacks *stacks, char *instruction)
{
	if (!ft_strncmp(instruction, "sa\n", ft_strlen("sa\n")))
		return (sa(&stacks->stack_a, 0), 1);
	else if (!ft_strncmp(instruction, "sb\n", ft_strlen("sb\n")))
		return (sb(&stacks->stack_b, 0), 1);
	else if (!ft_strncmp(instruction, "ss\n", ft_strlen("ss\n")))
		return (ss(&stacks->stack_a, &stacks->stack_b, 0), 1);
	else if (!ft_strncmp(instruction, "ra\n", ft_strlen("ra\n")))
		return (ra(&stacks->stack_a, 0), 1);
	else if (!ft_strncmp(instruction, "rb\n", ft_strlen("rb\n")))
		return (rb(&stacks->stack_b, 0), 1);
	else if (!ft_strncmp(instruction, "rr\n", ft_strlen("rr\n")))
		return (rr(&stacks->stack_a, &stacks->stack_b, 0), 1);
	else if (!ft_strncmp(instruction, "rra\n", ft_strlen("rra\n")))
		return (rra(&stacks->stack_a, 0), 1);
	else if (!ft_strncmp(instruction, "rrb\n", ft_strlen("rrb\n")))
		return (rrb(&stacks->stack_b, 0), 1);
	else if (!ft_strncmp(instruction, "rrr\n", ft_strlen("rrr\n")))
		return (rrr(&stacks->stack_a, &stacks->stack_b, 0), 1);
	else if (!ft_strncmp(instruction, "pa\n", ft_strlen("pa\n")))
		return (pa(&stacks->stack_a, &stacks->stack_b, 0), 1);
	else if (!ft_strncmp(instruction, "pb\n", ft_strlen("pb\n")))
		return (pb(&stacks->stack_a, &stacks->stack_b, 0), 1);
	else
		return (0);
}

void	handle_user_instructions(t_stacks *stacks)
{
	char	*move;

	move = get_next_line(0);
	while (move != NULL)
	{
		if (!execute_instruction(stacks, move))
			wrexit("Error\n");
		free(move);
		move = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	t_node		*lis;

	stacks.stack_a = parse_input(ac, av);
	stacks.stack_b = NULL;
	handle_user_instructions(&stacks);
	lis = longest_increasing_subsquence(stacks.stack_a);
	if (ll_size(lis) == ll_size(stacks.stack_a))
		write(1, "OK\n", ft_strlen("OK\n"));
	else
		write(1, "KO\n", ft_strlen("KO\n"));
	exit(0);
}
