/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:51:56 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/18 15:52:26 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "linked_list.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_stacks {
	t_node	*stack_a;
	t_node	*stack_b;
}	t_stacks;

extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern size_t	ft_strlen(const char *s);
extern void		split_clear(char	**arr);
extern char		**ft_split(char const *s, char c);
extern long		ft_atol(const char *str);
extern int		ft_strncmp(const char *s1, const char *s2, size_t n);
extern void		*ft_memcpy(void *dst, const void *src, size_t n);
extern size_t	ft_strlcpy(char *dst, const char *src, size_t size);
extern void		pa(t_node	**stack_a, t_node	**stack_b, int should_print);
extern void		pb(t_node	**stack_a, t_node	**stack_b, int should_print);
extern void		ra(t_node	**stack_a, int should_print);
extern void		rb(t_node	**stack_b, int should_print);
extern void		rr(t_node	**stack_a, t_node	**stack_b, int should_print);
extern void		rra(t_node	**stack_a, int should_print);
extern void		rrb(t_node	**stack_b, int should_print);
extern void		rrr(t_node	**stack_a, t_node	**stack_b, int should_print);
extern void		sa(t_node	**stack_a, int should_print);
extern void		sb(t_node	**stack_b, int should_print);
extern void		ss(t_node	**stack_a, t_node	**stack_b, int should_print);
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
extern int		where_at_a(t_stacks *stacks, int value);
extern void		execute_best_move_to_a(t_stacks *stacks, int bma[3]);
extern int		total_moves_needed(int moves_a, int moves_b);
extern void		find_best_move_to_a(t_stacks	*stacks, int bma[3]);
extern int		best_move_to_a(t_stacks *stacks);
extern t_node	*build_result_list(t_node *seq, t_node *indexes,
					int max_length, int max_index);
extern t_node	*longest_increasing_subsquence(t_node	*seq);
extern void		move_non_lis(t_stacks	*stacks, t_node	*lis);
extern int		is_sorted(t_node *stack);
extern void		sort_3(t_stacks	*stacks);
extern void		sort_5(t_stacks	*stacks);
extern void		cheesy_swap(t_stacks *stacks);
extern void		exit_gracefully(t_stacks *stacks);
extern int		abs(int x);
extern t_node	*create_ll_from_string(char *str);
extern int		is_number(char *str);
extern void		wrexit(char *str);
extern t_node	*parse_input(int ac, char **av);

#endif