/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:07:57 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/10 20:08:33 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*newnode;

	if (!lst || !f)
		return (NULL);
	head = NULL;
	head = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		newnode = ft_lstnew(lst->content);
		if (!newnode)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		newnode->content = f(lst->content);
		ft_lstadd_back(&head, newnode);
		lst = lst->next;
	}
	return (head);
}
