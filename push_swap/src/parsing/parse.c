/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:23:19 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/29 08:45:23 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit_parsing(char	**arr, t_node	**head, char *str, int is_heap)
{
	if (is_heap)
		free(str);
	split_clear(arr);
	ll_clear(head);
	wrexit("Error\n");
}

t_node	*create_ll_from_string(char *str, int is_heap)
{
	t_node	*head;
	char	**arr;
	long	tmp;
	int		i;

	i = 0;
	arr = ft_split(str, ' ');
	if (!arr)
		wrexit("A malloc failed\n");
	head = NULL;
	while (arr[i])
	{
		tmp = ft_atol(arr[i]);
		if (is_number(arr[i]) && INT_MIN <= tmp && tmp <= INT_MAX
			&& (ll_is_in(head, tmp) == -1))
			ll_push(&head, ll_new(tmp));
		else
			quit_parsing(arr, &head, str, is_heap);
		i++;
	}
	split_clear(arr);
	return (head);
}

char	*join_words(char **words, char *sep)
{
	int		i;
	int		result_len;
	char	*result;
	char	*builder;

	i = 0;
	result_len = 0;
	while (words[i])
		result_len += ft_strlen(words[i++]);
	result_len += (i - 1) * ft_strlen(sep) + 1;
	result = malloc(result_len * sizeof(char));
	if (!result)
		return (NULL);
	builder = result;
	i = 0;
	while (words[i])
	{
		if (i != 0)
			builder += ft_strlcpy(builder, sep, result_len);
		builder += ft_strlcpy(builder, words[i], result_len);
		i++;
	}
	*builder = 0;
	return (result);
}

t_node	*parse_input(int ac, char **av)
{
	t_node	*stack_a;
	char	*nbrs_str;

	if (ac < 2)
		exit(0);
	if (ac == 2)
	{
		stack_a = create_ll_from_string(av[1], 0);
		if (!stack_a)
			exit(0);
	}
	else
	{
		nbrs_str = join_words(++av, " ");
		stack_a = create_ll_from_string(nbrs_str, 1);
		free(nbrs_str);
	}
	return (stack_a);
}
