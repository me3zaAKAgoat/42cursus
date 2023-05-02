/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:51:56 by echoukri          #+#    #+#             */
/*   Updated: 2023/05/02 23:42:33 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "linked_list.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_meta {
	t_node	*stack_a;
	t_node	*stack_b;
}	t_meta;

extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern size_t	ft_strlen(const char *s);
extern void		split_clear(char	**arr);
extern char		**ft_split(char const *s, char c);
extern int		ft_atoi(const char *str);
extern void		pa(t_meta	*meta);
extern void		pb(t_meta	*meta);
extern void		ra(t_meta	*meta);
extern void		rb(t_meta	*meta);
extern void		rr(t_meta	*meta);
extern void		sa(t_meta	*meta);
extern void		sb(t_meta	*meta);

#endif