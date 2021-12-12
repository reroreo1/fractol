/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtoblack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:58:01 by rezzahra          #+#    #+#             */
/*   Updated: 2021/12/10 22:59:27 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void backtoblack(t_mlx *w)
{
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
            buffer[(j * line_bytes) + i] = 0;
            i++;
        }
        j++;
    }
    mlx_put_image_to_window(w->mlx,w->win,w->image,0,0);
}