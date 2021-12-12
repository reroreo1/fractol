/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:00:38 by rezzahra          #+#    #+#             */
/*   Updated: 2021/12/07 12:16:42 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	p = (char *)malloc((i + 1) * sizeof(char));
	if (p == 0)
		return (0);
	while (str[j])
	{
		p[j] = str[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}
