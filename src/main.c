/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:08:35 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/04 20:36:25 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	del(void *p)
{
	free(p);
}

int round_float(float x)
{
    int rounded;
	
	rounded = (int)(x + 0.5);
    if (x < 0.0) {
        rounded = (int)(x - 0.5);
    }
    return rounded;
}

void	ra_or_rra(t_meta	*meta, int	value)
{
	int	moves;
	int index;
	
	index = ll_is_in(meta->stack_a, value);
	if (index > (ll_size(meta->stack_a) - 1) / 2)
	{
		moves = -(index - (ll_size(meta->stack_a) - 1) / 2 + 1);
		while (moves++)
			ra(meta);
	}
	else
	{
		moves = index;
		while (moves--)
			rra(meta);
	}
}

void	rb_or_rrb(t_meta	*meta, int	value)
{
	int	moves;
	int index;
	
	index = ll_is_in(meta->stack_b, value);
	if (index > (ll_size(meta->stack_b) - 1) / 2)
	{
		moves = -(index - (ll_size(meta->stack_b) - 1) / 2);
		while (moves++)
			rb(meta);
	}
	else
	{
		moves = index;
		while (moves--)
			rrb(meta);
	}
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
	printf("\n");
}

t_node	*create_ll_from_string(char *str)
{
	t_node	*head;
	char	**arr;
	int		i;

	i = 1;
	arr = ft_split(str, ' ');
	head = ll_new(ft_atoi(*arr));
	while (*(arr + i))
	{
		ll_push(&head, ll_new(ft_atoi(*(arr + i))));
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
			ra_or_rra(meta, iterator->value);
			pb(meta);
			iterator = meta->stack_a;
		}
		else
			iterator = iterator->next;
	}
}


/*
info array goes this way
{number, moves on a, moves on b}
*/
// int	best_move(t_meta	*meta)
// {
// 	int		info[3];
// 	t_node	*iterator;

// 	iterator = meta->stack_b;
// 	while (iterator)
// 	{
// 		info[0] = iterator->value;
// 		ll_size(meta->stack_b) - ll_is_in(meta->stack_b, );
// 		iterator = iterator->next;
// 	}
// }


void	smallest_n_first(t_meta	*meta)
{
	int		min;
	t_node	*iterator;

	iterator = meta->stack_a;
	min = iterator->value;
	iterator = iterator->next;
	while (iterator)
	{
		if (iterator->value < min)
			min = iterator->value;
		iterator = iterator->next;
	}
	ra_or_rra(meta, min);
}

int	main(int ac, char **av)
{
	t_meta	meta;
	t_node	*lis;

	if (ac < 2)
		exit(1);
	meta.stack_b = NULL;
	meta.stack_a = create_ll_from_string(av[1]);
	ll_print(meta.stack_a);
	smallest_n_first(&meta);
	lis = longest_increasing_subsquence(meta.stack_a);
	ll_print(meta.stack_a);
	ll_print(lis);
	ll_print(meta.stack_b);
	move_non_lis(&meta, lis);
	ll_print(meta.stack_a);
	ll_print(lis);
	ll_print(meta.stack_b);
	ll_clear(&lis);
	ll_clear(&meta.stack_a);
	ll_clear(&meta.stack_b);
	exit(0);
}
