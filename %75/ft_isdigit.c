/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:13:30 by rezzahra          #+#    #+#             */
/*   Updated: 2021/12/09 19:48:18 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(char *c)
{
	char *s;
	size_t j;
	size_t i;
	if (!c)
		return 0;
	s = nopoint(c);
	i = 0;
	j = 0;
	if(c[j] == '-')
		i++;
	while (s[i] && s[i] >= 48 && s[i] <= 57 )
		i++;
	if(i == ft_strlen(s))
		return (1);
	else
		return (0);
}
