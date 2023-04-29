/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:50:37 by echoukri          #+#    #+#             */
/*   Updated: 2023/04/29 00:38:02 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

typedef struct list_item {
	int				value;
	int				index;
	t_list_item		*next;
} t_list_item;

extern void             ft_lstadd_back(t_list_item **lst, t_list_item *new);
extern void             ft_lstadd_front(t_list_item **lst, t_list_item *new);
extern void             ft_lstclear(t_list_item     **lst, void (*del)(void *));
extern void             ft_lstdelone(t_list_item *lst, void (*del)(void      *));
extern void             ft_lstiter(t_list_item	*lst, void (*f)(void    *));
extern t_list_item  *ft_lstlast(t_list_item *lst);
extern t_list_item  *ft_lstnew(void *content);
extern int              ft_lstsize(t_list_item *lst);
extern t_list_item  *ft_lstmap(t_list_item      *lst, void      *(*f)(void *),
                                        void (*del)(void *));

#endif