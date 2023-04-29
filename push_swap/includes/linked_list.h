/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:50:37 by echoukri          #+#    #+#             */
/*   Updated: 2023/04/29 18:32:18 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node {
	int				content;
	struct s_node	*next;
}	t_node;

extern void			ft_lstadd_back(t_node **lst, t_node *new);
extern void			ft_lstadd_front(t_node **lst, t_node *new);
extern void			ft_lstclear(t_node	**lst, void (*del)(void *));
extern void			ft_lstdelone(t_node	*lst, void (*del)(void	*));
extern void			ft_lstiter(t_node	*lst, void (*f)(void	*));
extern t_node		*ft_lstlast(t_node	*lst);
extern t_node		*ft_lstnew(void *content);
extern int			ft_lstsize(t_node *lst);
extern t_node		*ft_lstmap(t_node	*lst, void	*(*f)(void *),
						void (*del)(void *));

#endif