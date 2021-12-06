/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:34:39 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/10 21:06:15 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	words_count(const char *s, char c)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	while (s[i])
	{
		if (!set(s[i], c))
		{
			while (!set(s[i], c) && s[i])
				i++;
			compt++;
		}
		i++;
	}
	return (compt);
}

static char	*ft_strndup(const char *str, int size)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)malloc(size + 1);
	if (!p)
		return (0);
	while (str[i] && i < size)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static int	iterate(char **p, char const *s, char c)
{
	int		j;
	int		k;
	int		i;

	i = -1;
	j = 0;
	k = 0;
	while (s[++i])
	{	
		if (!set(s[i], c) && s[i])
		{
			j = i;
			while (!set(s[j], c) && s[j])
				j++;
			p[k++] = ft_strndup(s + i, j - i);
			i = j - 1;
		}
	}
	return (k);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	char	**p;

	k = 0;
	p = NULL;
	if (!s)
		return (NULL);
	p = (char **)malloc((words_count(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	k = iterate(p, s, c);
	p[k] = NULL;
	return (p);
}
