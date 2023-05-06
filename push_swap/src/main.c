/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:08:35 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/07 00:56:44 by echoukri         ###   ########.fr       */
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

int	moves_needed_to_top(t_node	*stack_x, int	value)
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
	int	n;

	n = moves_needed_to_top(*stack_x, value);
	rotate_n_times(stack_x, n, rx, rrx);
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


int	where_at_a(t_meta	*meta, int	value)
{
	int	i;
	int	size;

	if ((ll_min(meta->stack_a) > value ||
		value > ll_max(meta->stack_a)))
		return (moves_needed_to_top(meta->stack_a, ll_min(meta->stack_a)));
	i = 0;
	size = ll_size(meta->stack_a);
	while (i < size)
	{
		if (ll_value_atindex(meta->stack_a, i) < value &&
			value < ll_value_atindex(meta->stack_a, (i + 1) % size))
			break ;
		i++;
	}
	return (moves_needed_to_top(meta->stack_a, ll_value_atindex(meta->stack_a, (i + 1) % size)));
}

void	execute_best_move_to_a(t_meta	*meta, int	bma[3])
{
	while (bma[1] < 0 && bma[2] < 0)
	{
		rrr(&meta->stack_a, &meta->stack_b);
		bma[1]++;
		bma[2]++;
	}
	while (bma[1] > 0 && bma[2] > 0)
	{
		rr(&meta->stack_a, &meta->stack_b);
		bma[1]--;
		bma[2]--;
	}
	rotate_n_times(&meta->stack_a, bma[1], ra, rra);
	rotate_n_times(&meta->stack_b, bma[2], rb, rrb);
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
	

void	find_best_move_to_a(t_meta	*meta, int bma[3])
{
	int		tmp[3];
	t_node	*iterator;

	iterator = meta->stack_b;
	bma[0] = iterator->value;
	bma[1] = where_at_a(meta, iterator->value);
	bma[2] = moves_needed_to_top(meta->stack_b, iterator->value);
	iterator = iterator->next;
	while (iterator)
	{
		tmp[0] = iterator->value;
		tmp[1] = where_at_a(meta, iterator->value);
		tmp[2] = moves_needed_to_top(meta->stack_b, iterator->value);
		if (total_moves_needed(tmp[1], tmp[2]) < total_moves_needed(bma[1], bma[2]))
		{
			bma[0] = tmp[0];
			bma[1] = tmp[1];
			bma[2] = tmp[2];
		}
		iterator = iterator->next;
	}
}

int	best_move_to_a(t_meta	*meta)
{
	int		bma[3];

	find_best_move_to_a(meta, bma);
	execute_best_move_to_a(meta, bma);
	return (bma[0]);
}

void	smallest_to_top(t_node	**stack_x, void	(rx)(t_node	**stack_x, int should_print), void	(rrx)(t_node	**stack_x, int should_print))
{
	int		min;

	min = ll_min(*stack_x);
	rotate_to_top(stack_x, min, rx, rrx);
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

int	main(int ac, char **av)
{
	t_meta	meta;
	t_node	*lis;

	if (ac < 2)
		exit(1);
	meta.stack_b = NULL;
	meta.stack_a = create_ll_from_string(av[1]);

	lis = longest_increasing_subsquence(meta.stack_a);

	move_non_lis(&meta, lis);

	while (meta.stack_b)
		best_move_to_a(&meta);
	
	smallest_to_top(&meta.stack_a, ra, rra);

	// ll_print(meta.stack_a);
	
	ll_clear(&lis);
	ll_clear(&meta.stack_a);
	ll_clear(&meta.stack_b);
	exit(0);
}
