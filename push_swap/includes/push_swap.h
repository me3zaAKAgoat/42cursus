/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:51:56 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/07 19:12:20 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "linked_list.h"
# include <unistd.h>
# include <limits.h>
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
extern long		ft_atol(const char *str);
extern void		pa(t_node	**stack_a, t_node	**stack_b);
extern void		pb(t_node	**stack_a, t_node	**stack_b);
extern void		ra(t_node	**stack_a, int should_print);
extern void		rb(t_node	**stack_b, int should_print);
extern void		rr(t_node	**stack_a, t_node	**stack_b);
extern void		rra(t_node	**stack_a, int should_print);
extern void		rrb(t_node	**stack_b, int should_print);
extern void		rrr(t_node	**stack_a, t_node	**stack_b);
extern void		sa(t_node	**stack_a, int should_print);
extern void		sb(t_node	**stack_b, int should_print);
extern void		ss(t_node	**stack_a, t_node	**stack_b);
extern int		moves_needed_to_top(t_node *stack_x, int value);
extern void		rotate_n_times(t_node **stack_x, int moves,
					void (rx)(t_node **stack_x, int should_print),
					void (rrx)(t_node	**stack_x, int should_print));
extern void		rotate_to_top(t_node **stack_x, int value,
					void (rx)(t_node **stack_x, int should_print),
					void (rrx)(t_node **stack_x, int should_print));
extern void		smallest_to_top(t_node **stack_x,
					void (rx)(t_node **stack_x, int should_print),
					void (rrx)(t_node **stack_x, int should_print));
extern int		where_at_a(t_meta *meta, int value);
extern void		execute_best_move_to_a(t_meta *meta, int bma[3]);
extern int		total_moves_needed(int moves_a, int moves_b);
extern void		find_best_move_to_a(t_meta	*meta, int bma[3]);
extern int		best_move_to_a(t_meta *meta);
extern t_node	*build_result_list(t_node *seq, t_node *indexes,
					int max_length, int max_index);
extern t_node	*longest_increasing_subsquence(t_node	*seq);
extern void		move_non_lis(t_meta	*meta, t_node	*lis);
extern int		abs(int x);
extern t_node	*create_ll_from_string(char *str);
extern int		is_number(char *str);
extern void		wrexit(char *str, int code);
extern t_node	*parse_input(int ac, char **av);

#endif