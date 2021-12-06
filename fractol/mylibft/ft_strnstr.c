/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:08:31 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/06 19:37:32 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	char	*big1;

	i = 0;
	if (big[0] == '\0' || little[0] == '\0')
		if (little[0] == '\0')
			return ((char *)big);
	big1 = (char *)big;
	if (little == NULL)
		return (big1);
	while (i < n && big1[i])
	{
		j = 0;
		while (big1[i + j] == little[j])
		{
			if (j == ft_strlen(little) - 1 && i + j < n)
				return (&big1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
