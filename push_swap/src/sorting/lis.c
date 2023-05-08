/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:24:29 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/08 21:22:20 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*build_result_list(t_node *seq, t_node *indexes,
			int max_length, int max_index)
{
	t_node	*result;
	int		i;

	result = ll_fill_int(max_length, 0);
	i = max_index;
	while (i >= 0)
	{
		max_length--;
		(*ll_atindex(result, max_length)).value = ll_value_atindex(seq, i);
		i = ll_value_atindex(indexes, i);
	}
	return (result);
}

void	find_lengths_and_indexes(t_node *seq, t_node *lengths, t_node *indexes)
{
	int	i;
	int	j;
	int	sequence_length;

	i = 0;
	sequence_length = ll_size(seq);
	while (i < sequence_length)
	{
		j = 0;
		while (j < i)
		{
			if (ll_value_atindex(seq, j) < ll_value_atindex(seq, i)
				&& ll_value_atindex(lengths, j) + 1
				> ll_value_atindex(lengths, i))
			{
				(*ll_atindex(lengths, i)).value
					= ll_value_atindex(lengths, j) + 1;
				(*ll_atindex(indexes, i)).value = j;
			}
			j++;
		}
		i++;
	}
}

void	max_length_and_index(t_node *seq, t_node *lengths,
	int *max_index_p, int *max_length_p)
{
	int	i;
	int	sequence_length;

	sequence_length = ll_size(seq);
	(*max_length_p) = 0;
	i = 0;
	while (i < sequence_length)
	{
		if (ll_value_atindex(lengths, i) > (*max_length_p))
		{
			(*max_length_p) = ll_value_atindex(lengths, i);
			(*max_index_p) = i;
		}
		i++;
	}
}

t_node	*longest_increasing_subsquence(t_node	*seq)
{
	int		max_length;
	int		max_index;
	t_node	*lengths;
	t_node	*indexes;
	t_node	*result;

	lengths = ll_fill_int(ll_size(seq), 1);
	indexes = ll_fill_int(ll_size(seq), -1);
	find_lengths_and_indexes(seq, lengths, indexes);
	max_length_and_index(seq, lengths, &max_index, &max_length);
	result = build_result_list(seq, indexes, max_length, max_index);
	ll_clear(&indexes);
	ll_clear(&lengths);
	return (result);
}

void	move_non_lis(t_stacks	*stacks, t_node	*lis)
{
	t_node	*iterator;

	iterator = stacks->stack_a;
	while (iterator)
	{
		if (ll_is_in(lis, iterator->value) == -1)
		{
			rotate_to_top(&stacks->stack_a, iterator->value, ra, rra);
			pb(&stacks->stack_a, &stacks->stack_b);
			iterator = stacks->stack_a;
		}
		else
			iterator = iterator->next;
	}
}
