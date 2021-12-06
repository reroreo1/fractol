/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:50:43 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/06 17:50:58 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*ptrsrc;
	unsigned char		*ptrdst;

	i = 0;
	if (!src && !dest)
		return (NULL);
	ptrsrc = src;
	ptrdst = dest;
	if (ptrdst > ptrsrc)
	{
		while (n--)
			ptrdst[n] = ptrsrc[n];
		return (dest);
	}
	while (i < n)
	{
		ptrdst[i] = ptrsrc[i];
		i++;
	}
	return (dest);
}
