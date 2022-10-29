/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoukri <echoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:01:15 by echoukri          #+#    #+#             */
/*   Updated: 2022/10/29 00:59:42 by echoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list	*lst, void	*(*f)(void *), void (*del)(void *))
{
	t_list	*head_ptr;
	t_list	*new_ptr;

	if (!lst || !f || !del)
		return (NULL);
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
