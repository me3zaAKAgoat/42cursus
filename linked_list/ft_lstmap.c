/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:01:15 by echoukri          #+#    #+#             */
/*   Updated: 2023/04/29 00:31:52 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list_item	*ft_lstmap(t_list_item	*lst, void	*(*f)(void *), void (*del)(void *))
{
	t_list_item	*head_ptr;
	t_list_item	*new_ptr;

	head_ptr = NULL;
	while (lst)
	{
		new_ptr = ft_lstnew(f(lst->content));
		if (!new_ptr)
		{
			ft_lstclear(&head_ptr, del);
			return (NULL);
		}
		ft_lstadd_back(&head_ptr, new_ptr);
		lst = lst->next;
	}
	return (head_ptr);
}
