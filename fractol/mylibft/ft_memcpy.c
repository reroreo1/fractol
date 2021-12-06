/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:52:11 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/07 17:02:31 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c;
	unsigned char	*b;

	if (!src && !dest)
		return (NULL);
	c = (unsigned char *) dest;
	b = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		c[i] = b[i];
		i++;
	}
	return (dest);
}
