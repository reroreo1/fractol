/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:01:58 by rezzahra          #+#    #+#             */
/*   Updated: 2021/11/06 21:16:41 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nb(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*allocate(int size)
{
	char	*ptr;

	ptr = malloc(size * sizeof(char));
	if (!ptr)
		return (0);
	return (ptr);
}

char	*ft_itoa(int nb)
{
	char	*ptr;
	int		len;
	long	nb2;
	int		i;

	nb2 = nb;
	len = count_nb(nb);
	i = len;
	if (nb2 < 0)
		nb2 *= -1;
	ptr = allocate(len + 1);
	if (!ptr)
		return (NULL);
	if (nb < 0)
		ptr[0] = '-';
	len--;
	while (len >= 0)
	{
		if (nb < 0 && len == 0)
			break ;
		ptr[len--] = nb2 % 10 + '0';
		nb2 /= 10;
	}
	ptr[i] = '\0';
	return (ptr);
}
