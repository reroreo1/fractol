/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:06:53 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/10 21:13:05 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*p;

	i = 0;
	j = 0;
	p = NULL;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	p = (char *)malloc((i + 1) * sizeof(char));
	if (!p)
		return (p);
	while (s[j])
	{
		p[j] = f(j, s[j]);
		j++;
	}
	p[j] = '\0';
	return (p);
}
