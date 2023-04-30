/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:50:37 by echoukri          #+#    #+#             */
/*   Updated: 2023/04/30 23:29:11 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

extern void			lst_push(t_node **lst, t_node *new);
extern void			lst_unshift(t_node **lst, t_node *new);
extern void			lst_clear(t_node	**lst);
extern void			lst_del_one(t_node *lst);
extern void			lst_iter(t_node	*lst, int (f)(void	*));
extern t_node		*lst_last(t_node	*lst);
extern t_node		*lst_new(int	value);
extern int			lst_size(t_node *lst);
extern t_node		*lst_map(t_node	*lst, int	(f)(void *));
extern t_node		*lst_fill_int(int	length, int value);
extern int			lst_get_index(t_node	*head, t_node *node);
extern t_node		*lst_atindex(t_node *head, int index);
extern int			lst_value_atindex(t_node *head, int index);

#endif