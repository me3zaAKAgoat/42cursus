/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:08:35 by echoukri          #+#    #+#             */
/*   Updated: 2023/04/30 23:29:11 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	del(void *p)
{
	free(p);
}

t_node	*create_linked_list_from_string(char *str)
{
	t_node	*head;
	char	**arr;
	int		i;

	i = 1;
	arr = ft_split(str, ' ');
	head = lst_new(ft_atoi(*arr));
	while (*(arr + i))
	{
		lst_push(&head, lst_new(ft_atoi(*(arr + i))));
		i++;
	}
	split_clear(arr);
	return (head);
}

t_node	*longest_increasing_subsquence(t_node	*seq)
{
	int		sequence_length;
	int 	i;
	int 	j;
	t_node	*lengths;
	t_node	*indexes;
	t_node	*result;
	int		max_length;
	
	max_length = 0;
	sequence_length = lst_size(seq);
	lengths = lst_fill_int(sequence_length, 1);
	indexes = lst_fill_int(sequence_length, -1);
	i = 0;
	while (i < sequence_length)
	{
		j = 0;
		while (j < i)
		{
			if (lst_value_atindex(seq, j) < lst_value_atindex(seq, i) && lst_value_atindex(lengths, j) + 1 >  lst_value_atindex(lengths, i))
			{
				lst_atindex(lengths, i)->value = lst_value_atindex(lengths, j) + 1;
				lst_atindex(indexes, i)->value = j;
			}
			j++;
		}
		
		if (lst_value_atindex(lengths, i) > max_length)
			max_length = lst_value_atindex(lengths, i);
		i++;
	}
	i--;

	result = lst_fill_int(max_length, 0);
	while (i >= 0)
	{
		max_length--;
		lst_atindex(result, max_length)->value = lst_value_atindex(seq, i);
		i = lst_value_atindex(indexes, i);
	}

	return (result);
}

int	main(int ac, char **av)
{
	t_node	*head;
	t_node	*iterator;
	t_node	*lis;

	if (ac < 2)
		exit(1);
	head = create_linked_list_from_string(av[1]);
	lis = longest_increasing_subsquence(head);
	iterator = lis;
	while (iterator)
	{
		printf("%d\n", iterator->value);
		iterator = iterator->next;
	}
	// lst_clear(&head);
	// system("leaks push_swap");
	exit(0);
}
