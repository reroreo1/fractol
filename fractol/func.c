/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:48:11 by rezzahra          #+#    #+#             */
/*   Updated: 2021/12/11 01:57:18 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
extern t_mlx *w;

int func(int k)
{
	if(k == 53)
	{
		quit();
	}
	if(k == 4)
	{
		w->st1 = w->st1 * 0.8f;
		w->st2 = w->st2 * 0.8f;
	}
	if(k == 5)
	{
		w->st1 = w->st1 / 0.8f;
		w->st2 = w->st2 / 0.8f;
	}
	if (w->is_julia == 1)
	{
		backtoblack(w);
		julia(w);
	}
	else if (w->is_julia == 0)
	{
		backtoblack(w);
		mandelbrot(w);
	}
	else if (w->is_julia == 2)
	{
		backtoblack(w);
		myset(w);
	}
	return 0;
}
