/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:08:35 by echoukri          #+#    #+#             */
/*   Updated: 2023/04/29 18:44:54 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	**arr;
	int		*converted_int;
	t_node	*head;

	if (ac < 2)
		exit(1);
	arr = ft_split(av[1], ' ');
	converted_int = malloc(sizeof(int));
	*converted_int = ft_atoi(*arr);
	head = ft_lstnew(converted_int);
	arr++;
	while (*arr)
	{
		converted_int = malloc(sizeof(int));
		*converted_int = ft_atoi(*arr);
		ft_lstadd_back(&head, ft_lstnew(converted_int));
		arr++;
	}
	while (head)
	{
		printf("%d\n", head->content);
		head++;
	}
	split_clear(arr);
	exit(0);
}