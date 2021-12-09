/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:56:53 by rezzahra          #+#    #+#             */
/*   Updated: 2021/12/07 10:57:03 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*set1;
	unsigned char	*set2;

	set1 = (unsigned char *)s1;
	set2 = (unsigned char *)s2;
	i = 0;
	while ((set1[i] || set2[i]))
	{
		if (set1[i] != set2[i])
		{
			return (set1[i] - set2[i]);
		}
		i++;
	}
	return (0);
}
