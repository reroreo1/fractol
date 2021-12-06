/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:39:29 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/10 20:50:56 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ifset(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*p;

	p = NULL;
	k = 0;
	i = 0;
	j = 0;
	if ((!s1 || !set))
		return (NULL);
	j = ft_strlen(s1) - 1;
	while (ifset(s1[j], set))
		j--;
	if (j <= 0)
		return (ft_strdup(""));
	while (ifset(s1[i], set))
		i++;
	p = malloc((j - i + 2) * sizeof(char));
	if (!p)
		return (0);
	while (i <= j)
		p[k++] = s1[i++];
	p[k] = 0;
	return (p);
}
