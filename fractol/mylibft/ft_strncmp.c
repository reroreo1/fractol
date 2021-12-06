/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:57:48 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/06 19:35:54 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*set1;
	unsigned char	*set2;

	set1 = (unsigned char *)s1;
	set2 = (unsigned char *)s2;
	i = 0;
	while ((set1[i] || set2[i]) && i < n)
	{
		if (set1[i] != set2[i])
		{
			return (set1[i] - set2[i]);
		}
		i++;
	}
	return (0);
}
