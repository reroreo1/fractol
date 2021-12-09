/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:57:57 by rezzahra          #+#    #+#             */
/*   Updated: 2021/12/09 19:49:19 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char *nopoint(const char *num)
{
    int size;
    char *s;
    if (ft_strchr(num,'.') == NULL)
        return ((char *)num);
    size = ft_strchr(num,'.') - num  + 1;
    num = ft_strjoin(ft_substr(num,0,size - 1),ft_substr(num,size, ft_strlen(num) - size));
    s = (char *)num;
    return (s);
}

float ft_itof(const char *num)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    if(!num)
        return 0;
    if (ft_strchr(num,'.') == NULL)
        return (ft_atoi(nopoint(num)));  
    j =ft_strlen(ft_strchr(num, '.')) - 1;
    i = ft_atoi(nopoint(num));
    return (i / pow(10.f, j));
}

