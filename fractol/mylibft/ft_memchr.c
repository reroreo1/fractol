/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:19:53 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/06 17:46:26 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	b;

	i = 0;
	b = c;
	s = (unsigned char *)str;
	while (i < n)
	{
		if (s[i] == b)
			return (&s[i]);
		i++;
	}
	return (0);
}
