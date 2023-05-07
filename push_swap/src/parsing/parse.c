/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:23:19 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/07 19:12:44 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit_parsing(char	**arr)
{
	split_clear(arr);
	wrexit("Error\n", 1);
}

t_node	*create_ll_from_string(char *str)
{
	t_node	*head;
	char	**arr;
	long	tmp;
	int		i;

	i = 0;
	arr = ft_split(str, ' ');
	if (!arr)
		wrexit("Error\n", 1);
	head = NULL;
	while (arr[i])
	{
		tmp = ft_atol(arr[i]);
		if (is_number(arr[i]) && INT_MIN < tmp && tmp < INT_MAX)
		{
			if (ll_is_in(head, tmp) != -1)
				quit_parsing(arr);
			ll_push(&head, ll_new(tmp));
		}
		else
			quit_parsing(arr);
		i++;
	}
	split_clear(arr);
	return (head);
}

t_node	*parse_input(int ac, char **av)
{
	t_node	*stack_a;

	if (ac < 2)
		wrexit("Error\n", 1);
	stack_a = create_ll_from_string(av[1]);
	return (stack_a);
}
