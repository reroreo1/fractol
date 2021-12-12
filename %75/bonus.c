/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 01:48:12 by rezzahra          #+#    #+#             */
/*   Updated: 2021/12/12 17:26:36 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static float iteratei(t_z z, float step, int i, float st1)
{
    z.re = z.re * z.re * z.re - 3 * z.im * z.im * z.re + i * step + st1;
    return(z.re);
}

static float iteratej(t_z z, float step, int j, float temp)
{
    z.im = 3 * temp * temp * z.im  - z.im * z.im * z.im - j * step;
    return (z.im);
}

void myset(t_mlx *w)
{
    float temp;
    int n = 0;
    int i = 0;
    int j = 0;
    int *buffer;
    int  pixel_bits;
    int line_bytes;
    int endian;
    buffer = (int *)mlx_get_data_addr(w->image, &pixel_bits, &line_bytes, &endian);
    line_bytes /= 4;
    while(j < w->y)
    {
        i = 0;
        while(i < w->x)
        {
            n = 0;
            w->z.re = 0;
            w->z.im = 0;
            while (++n < 500 && w->z.re * w->z.re + w->z.im * w->z.im < 8)
            {
                temp = w->z.re;    
                w->z.re = iteratei(w->z,step(w->st1, w->st2, 0, w->x),i,w->st1);
                w->z.im = iteratej(w->z,step(w->st1, w->st2, 0, w->y),j,temp) + w->st2;
            }
            if (n < 500)
                buffer[(j * line_bytes) + i] = w->color * n;
            i++;
        }
        j++;
    }
    mlx_put_image_to_window(w->mlx, w->win, w->image, 0, 0);
}