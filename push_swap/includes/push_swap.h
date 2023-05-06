/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:51:56 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/06 01:46:46 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "linked_list.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_meta {
	t_node	*stack_a;
	t_node	*stack_b;
}	t_meta;

extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern size_t	ft_strlen(const char *s);
extern void		split_clear(char	**arr);
extern char		**ft_split(char const *s, char c);
extern int		ft_atoi(const char *str);
extern void		pa(t_node	**stack_a, t_node	**stack_b);
extern void		pb(t_node	**stack_a, t_node	**stack_b);
extern void		ra(t_node	**stack_a);
extern void		rb(t_node	**stack_b);
extern void		rr(t_node	**stack_a, t_node	**stack_b);
extern void		rra(t_node	**stack_a);
extern void		rrb(t_node	**stack_b);
extern void		rrr(t_node	**stack_a, t_node	**stack_b);
extern void		sa(t_node	**stack_a);
extern void		sb(t_node	**stack_b);

#endif