/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:08:35 by echoukri          #+#    #+#             */
/*   Updated: 2023/04/30 20:37:16 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	del(void *p)
{
	free(p);
}

t_node	*strtolinkedlist(char *str)
{
	t_node	*head;
	char	**arr;
	int		i;

	i = 1;
	arr = ft_split(str, ' ');
	head = ft_lstnew(ft_atoi(*arr));
	while (*(arr + i))
	{
		ft_lstadd_back(&head, ft_lstnew(ft_atoi(*(arr + i))));
		i++;
	}
	split_clear(arr);
	return (head);
}

t_node	*longest_increasing_subsquence(t_node	*seq)
{
	int		n;
	int 	i;
	int 	j;
	t_node	*lengths;
	t_node	*indexes;
	t_node	*result;
	int		max_length;
	int		max_index;
	
	max_length = 0;
	max_index = 0;
	n = ft_lstsize(seq);
	lengths = ft_lstfilled_w_int(n, 1);
	indexes = ft_lstfilled_w_int(n, -1);
	i = 0;
	while (i < n)
	{
		j = 0;
		printf("i : %d\n", i);
		while (j < i)
		{
			printf("j : %d\n", j);
			if (ft_lstvalueatindex(seq, j) < ft_lstvalueatindex(seq, i) && ft_lstvalueatindex(lengths, j) + 1 >  ft_lstvalueatindex(lengths, i))
			{
				puts("here");
				ft_lstatindex(seq, i)->value = ft_lstvalueatindex(seq, j) + 1;
				ft_lstatindex(seq, i)->value = j;
			}
			j++;
		}
		
		if (ft_lstvalueatindex(seq, j) > max_length)
		{
			max_length = ft_lstvalueatindex(seq, i);
			max_index = i;
		}
		i++;
	}
	puts("here");

	result = ft_lstfilled_w_int(max_length, 0);
	while (i >= 0)
	{
		ft_lstatindex(result, max_length--)->value = ft_lstvalueatindex(seq, i);
		i = ft_lstvalueatindex(indexes, i);
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
	head = strtolinkedlist(av[1]);
	lis = longest_increasing_subsquence(head);
	iterator = lis;
	while (iterator)
	{
		printf("%d\n", iterator->value);
		iterator = iterator->next;
	}
	ft_lstclear(&head);
	system("leaks push_swap");
	exit(0);
}
