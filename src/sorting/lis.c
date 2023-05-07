/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:24:29 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/07 15:37:04 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *build_result_list(t_node *seq, t_node *indexes,
			int max_length, int max_index)
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
