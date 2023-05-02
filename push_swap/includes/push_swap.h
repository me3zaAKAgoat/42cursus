/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:51:56 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/02 18:46:41 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "linked_list.h"
# include <unistd.h>
# include <stdlib.h>

extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern size_t	ft_strlen(const char *s);
extern void		split_clear(char	**arr);
extern char		**ft_split(char const *s, char c);
extern int		ft_atoi(const char *str);
extern void		pa(t_node	**stack_a_p, t_node	**stack_b_p);
extern void		pb(t_node	**stack_a_p, t_node	**stack_b_p);
extern void		ra(t_node	**stack_a_p);
extern void		rb(t_node	**stack_b_p);
extern void		rr(t_node	**stack_a_p, t_node	**stack_b_p);
extern void		sa(t_node	**stack_a_p);
extern void		sb(t_node	**stack_b_p);

#endif