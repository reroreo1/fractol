#include "fractol.h"

int main(int ac ,char **av)
{
    t_z c;
    if(av[1] != "Mandelbrot" && av[1] != "Julia")
        printf("this choice is unavailable\n pick Julia or Mandelbrot set");
    if(av[1] == "Mandelbrot")
    {    
        if(ft_atoi(av[2]) && ft_atoi(av[3]) && ft_atoi(av[4]))
            mandelbrot(ft_atoi(av[2]),ft_atoi(3),ft_atoi(av[4]));
        else
            printf("invalid arguments try again with valid ones");
    }
    if(av[1] == "Julia")
    {
        c.re = (float)ft_atoi(av[5]);
        c.im = (float)ft_atoi(av[6]);
        if(ft_atoi(av[2]) && ft_atoi(av[3]) && ft_atoi(av[4]))
            julia(ft_atoi(av[2]),ft_atoi(3),ft_atoi(av[4]),c);
        else
            printf("invalid arguments try again with valid ones");
    }
}