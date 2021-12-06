/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:29:34 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/06 19:22:37 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	destlen;
	int		i;

	i = 0;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (destlen > dstsize || !dstsize)
		return (srclen + dstsize);
	while (destlen + i < dstsize - 1 && src[i])
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (srclen + destlen);
}
