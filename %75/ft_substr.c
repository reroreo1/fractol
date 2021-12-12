/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:23:41 by rezzahra          #+#    #+#             */
/*   Updated: 2021/12/07 12:18:08 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char	*allocate(char const *s, size_t len)
{
	char	*p;

	if (ft_strlen(s) < len)
		p = (char *)malloc(ft_strlen(s) * sizeof(char));
	else
		p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = -1;
	j = -1;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	while (s[++i])
	{
		if (i == start)
		{
			p = allocate(s, len);
			if (!p)
				return (NULL);
			while (++j < len && s[i + j])
				p[j] = s[i + j];
			p[j] = '\0';
			return (p);
		}
	}
	return (0);
}
