/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:08:35 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/06 21:53:15 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int abs(int x)
{
	if (x < 0)
		return -x;
	else
		return x;
}

int	calc_moves_to_top(t_node	*stack_x, int	value)
{
	int	moves;
	int index;
	
	index = ll_is_in(stack_x, value);
	if (index > (ll_size(stack_x) - 1) / 2)
		moves = index - (ll_size(stack_x));
	else
		moves = index;
	return (moves);
}

void	rotate_n_times(t_node	**stack_x, int moves, void	(rx)(t_node	**stack_x, int should_print), void	(rrx)(t_node	**stack_x, int should_print))
{
	if (moves < 0)
		while (moves++)
			rrx(stack_x, 1);
	else if (moves > 0)
		while (moves--)
			rx(stack_x, 1);
}

void	rotate_to_top(t_node	**stack_x, int	value, void	(rx)(t_node	**stack_x, int should_print), void	(rrx)(t_node	**stack_x, int should_print))
{
	int	moves;

	moves = calc_moves_to_top(*stack_x, value);
	rotate_n_times(stack_x, moves, rx, rrx);
}

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

t_node	*create_ll_from_string(char *str)
{
	t_node	*head;
	char	**arr;
	int		i;

	i = 1;
	arr = ft_split(str, ' ');
	head = ll_new(ft_atoi(*arr));
	while (arr[i])
	{
		ll_push(&head, ll_new(ft_atoi(arr[i])));
		i++;
	}
	split_clear(arr);
	return (head);
}

t_node *build_result_list(t_node *seq, t_node *indexes, int max_length, int max_index)
{
	t_node *result;
	int 	i;
	
	result = ll_fill_int(max_length, 0);
	i = max_index;
	while (i >= 0) {
		max_length--;
		ll_atindex(result, max_length)->value = ll_value_atindex(seq, i);
		i = ll_value_atindex(indexes, i);
	}
	return (result);
}

t_node	*longest_increasing_subsquence(t_node	*seq)
{
	int 	i;
	int 	j;
	int		sequence_length;
	int		max_length;
	int		max_index;
	t_node	*lengths;
	t_node	*indexes;
	t_node	*result;
	
	max_length = 0;
	sequence_length = ll_size(seq);
	lengths = ll_fill_int(sequence_length, 1);
	indexes = ll_fill_int(sequence_length, -1);
	i = 0;
	while (i < sequence_length)
	{
		j = 0;
		while (j < i)
		{
			if (ll_value_atindex(seq, j) < ll_value_atindex(seq, i)
				&& ll_value_atindex(lengths, j) + 1 >  ll_value_atindex(lengths, i))
			{
				ll_atindex(lengths, i)->value = ll_value_atindex(lengths, j) + 1;
				ll_atindex(indexes, i)->value = j;
			}
			j++;
		}
		
		if (ll_value_atindex(lengths, i) > max_length)
		{
			max_length = ll_value_atindex(lengths, i);
			max_index = i;
		}
		i++;
	}

	result = build_result_list(seq, indexes, max_length, max_index);
	
	ll_clear(&indexes);
	ll_clear(&lengths);

	return (result);
}

void	move_non_lis(t_meta	*meta, t_node	*lis)
{
	t_node	*iterator;

	iterator = meta->stack_a;
	while (iterator)
	{
		if (ll_is_in(lis, iterator->value) == -1)
		{
			rotate_to_top(&meta->stack_a, iterator->value, ra, rra);
			pb(&meta->stack_a, &meta->stack_b);
			iterator = meta->stack_a;
		}
		else
			iterator = iterator->next;
	}
}

int	where_at_a(t_meta	*meta, int	value)
{
	int	i;
	int	size;

	if ((ll_min(meta->stack_a) > value ||
		value > ll_max(meta->stack_a)))
		return (calc_moves_to_top(meta->stack_a, ll_min(meta->stack_a)));
	i = 0;
	size = ll_size(meta->stack_a);
	while (i < size)
	{
		if (ll_value_atindex(meta->stack_a, i) < value &&
			value < ll_value_atindex(meta->stack_a, (i + 1) % size))
			break ;
		i++;
	}
	return (calc_moves_to_top(meta->stack_a, ll_value_atindex(meta->stack_a, (i + 1) % size)));
}

void	execute_best_move(t_meta	*meta, int	info[3])
{
	while ((info[1] < 0 && info[2] < 0)
		|| (info[1] > 0 && info[2] > 0))
	{
		if (info[1] < 0)
		{
			rr(&meta->stack_a, &meta->stack_b);
			info[1]++;
			info[2]++;
		}
		else
		{
			rrr(&meta->stack_a, &meta->stack_b);
			info[1]--;
			info[2]--;
		}
	}
	rotate_n_times(&meta->stack_a, info[1], ra, rra);
	rotate_n_times(&meta->stack_b, info[2], rb, rrb);
	pa(&meta->stack_a, &meta->stack_b);
}

int	total_moves_needed(int	moves_a, int moves_b)
{
	int	count;

	count = 0;
	while ((moves_a < 0 && moves_b < 0))
	{
			moves_a++;	
			moves_b++;	
			count++;	
	}
	while (moves_a > 0 && moves_b > 0)
	{
			moves_a--;	
			moves_b--;	
			count++;
	}
	count += (abs(moves_a) + abs(moves_b));
	return (count);
}
	
/*
info array goes this way
{number, moves on a, moves on b}
*/
int	find_best_move(t_meta	*meta)
{
	int		info[3];
	int		tmp[3];
	t_node	*iterator;

	iterator = meta->stack_b;
	info[0] = iterator->value;
	info[1] = where_at_a(meta, iterator->value);
	info[2] = calc_moves_to_top(meta->stack_b, iterator->value);
	iterator = iterator->next;
	// printf("%d b: %d a: %d\n", info[0], info[2], info[1]);
	while (iterator)
	{
		tmp[0] = iterator->value;
		tmp[1] = where_at_a(meta, iterator->value);
		tmp[2] = calc_moves_to_top(meta->stack_b, iterator->value);
		// printf("%d b: %d a: %d => test %d info %d\n", tmp[0], tmp[2], tmp[1], abs(tmp[1]) + abs(tmp[2]),  abs(info[1]) + abs(info[2]));
		// if (abs(tmp[1]) + abs(tmp[2]) < abs(info[1]) + abs(info[2]))
		// printf("%d b: %d a: %d => test %d info %d\n", tmp[0], tmp[2], tmp[1], abs(tmp[1] - tmp[2]),  abs(info[1] - info[2]));
		if (total_moves_needed(tmp[1], tmp[2]) < total_moves_needed(info[1], info[2]))
		{
			info[0] = tmp[0];
			info[1] = tmp[1];
			info[2] = tmp[2];
		}
		iterator = iterator->next;
	}
	// printf("best move was %d\n", info[0]);
	execute_best_move(meta, info);
	return (info[0]);
}

void	smallest_to_top(t_node	**stack_x, void	(rx)(t_node	**stack_x, int should_print), void	(rrx)(t_node	**stack_x, int should_print))
{
	int		min;

	min = ll_min(*stack_x);
	rotate_to_top(stack_x, min, rx, rrx);
}

int	main(int ac, char **av)
{
	t_meta	meta;
	t_node	*lis;

	if (ac < 2)
		exit(1);
	meta.stack_b = NULL;
	meta.stack_a = create_ll_from_string(av[1]);

	lis = longest_increasing_subsquence(meta.stack_a);

	// ll_print(meta.stack_a);
	// ll_print(lis);
	// ll_print(meta.stack_b);


	move_non_lis(&meta, lis);

	// ll_print(meta.stack_a);
	// ll_print(meta.stack_b);
	while (meta.stack_b)
	{
		find_best_move(&meta);
		// ll_print(meta.stack_a);
		// ll_print(meta.stack_a);
	}
	
	smallest_to_top(&meta.stack_a, ra, rra);
	// ll_print(meta.stack_a);

	ll_clear(&lis);
	ll_clear(&meta.stack_a);
	ll_clear(&meta.stack_b);
	exit(0);
}
