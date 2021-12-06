/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:54:42 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/10 14:38:08 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (del)(void*))
{
	t_list	*temp;
	t_list	*temp2;

	temp = *lst;
	while (temp)
	{
		temp2 = temp->next;
		del(temp->content);
		free(temp);
		temp = temp2;
	}
	*lst = NULL;
}
