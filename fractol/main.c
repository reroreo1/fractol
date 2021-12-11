#include "fractol.h"

t_mlx *w;

int main(int ac ,char **av)
{
    (void)ac;
    t_mlx ss;

    w = &ss;
    w->st1 = -2.f;
    w->st2 = 2.f;
    w->mlx = mlx_init();
    w->x = ft_atoi(av[2]);
    w->y = ft_atoi(av[3]);
    w->color = ft_atoi(av[4]);
    w->c.re = ft_itof(av[5]);
    w->c.im = ft_itof(av[6]);
    if(ft_strcmp(av[1],"Mandelbrot") != 0 && ft_strcmp(av[1],"Julia")!= 0 && ft_strcmp(av[1],"bonus")!= 0 )
        printf("this choice is unavailable\npick Julia or Mandelbrot set");
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
    if(ft_strcmp(av[1],"Julia") == 0)
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
    if(ft_strcmp(av[1],"bonus") == 0)
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
    mlx_hook(w->win, 4, 1L<<8, func, NULL);
    mlx_hook(w->win, 2, 1L<<0, func, NULL);
    mlx_hook(w->win, 17, 0, quit, NULL);
    mlx_loop(w->mlx);
}