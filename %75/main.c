/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:19:36 by rezzahra          #+#    #+#             */
/*   Updated: 2021/12/12 18:36:19 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int udrl(int k,t_mlx *w)
{
    if(k == 53)
	{
		quit();
        return (0);
	}
    if(k == 126)
        w->x++; 
    if(k == 125)
        w->x--;
    if(k == 124)
        w->y++;
    if(k == 123)
        w->y--; 
    return 0;
}
void events(t_mlx *w)
{
    mlx_hook(w->win,4, 1L<<8, zoom, w);
    mlx_hook(w->win, 2, 1L<<0, udrl, w);
    mlx_hook(w->win, 17, 0, quit, NULL);
}
int zoom(int k, int i, int j, t_mlx *w)
{
   (void)i;
   (void)j;

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
int update(t_mlx *w)
{
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
    return 1;
}
int main(int ac ,char **av)
{
    t_mlx *w;
    if (ac == 2)
        return 0;
    w = (t_mlx *)malloc(sizeof(t_mlx));
    if(ft_strcmp(av[1],"Mandelbrot") != 0 && ft_strcmp(av[1],"Julia")!= 0 && ft_strcmp(av[1],"bonus")!= 0 )
        printf("this choice is unavailable\npick Julia or Mandelbrot set");
    
    w->st1 = -2.f;
    w->st2 = 2.f;
    w->mlx = mlx_init();
    w->x = ft_atoi(av[2]);
    w->y = ft_atoi(av[3]);
    w->color = ft_atoi(av[4]);
    w->c.re = ft_itof(av[5]);
    w->c.im = ft_itof(av[6]);
    if(ft_strcmp(av[1],"Mandelbrot") == 0)
    {    
        if(ft_atoi(av[2]) && ft_atoi(av[3]) && ft_atoi(av[4]))
        {
            w->is_julia = 0;
            w->win = mlx_new_window(w->mlx,w->x,w->y,"Mandelbrot set");
            w->image = mlx_new_image(w->mlx, w->x, w->y);
            mandelbrot(w);
        }
        else
            printf("invalid arguments try again with valid ones");
    }
    else if(ft_strcmp(av[1],"Julia") == 0)
    {
        if(ft_isdigit(av[5]) == 1 && ft_isdigit(av[6]) == 1)
        {
            if(ft_atoi(av[2]) && ft_atoi(av[3]) && ft_atoi(av[4]))
            {  
                w->is_julia = 1;
                w->win = mlx_new_window(w->mlx,w->x,w->y,"Julia set");
                w->image = mlx_new_image(w->mlx, w->x, w->y);
                julia(w);
            }
            else
                printf("invalid arguments try again with valid ones");
        }
        else
            return 0;
    }
    else if(ft_strcmp(av[1],"bonus") == 0)
    {    
        if(ft_atoi(av[2]) && ft_atoi(av[3]) && ft_atoi(av[4]))
        {
            w->is_julia = 2;
            w->win = mlx_new_window(w->mlx,w->x,w->y,"bonus");
            w->image = mlx_new_image(w->mlx, w->x, w->y);
            myset(w);
        }
        else
            printf("invalid arguments try again with valid ones");
    }
    else
        return (0);
    events(w);
    mlx_loop_hook(w->mlx,&update, w);
    mlx_loop(w->mlx);
}