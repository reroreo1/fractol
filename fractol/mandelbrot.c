#include "fractol.h"

static float step(float x, float y,float x1,float y1)
{
    float i;

    i = 0.f;
    i = (x - y) / (x1 - y1);
    return i;
}

static void iterate(t_z *z, float step, int i, int j)
{
    float temp = z->re;
    z->re = z->re * z->re - z->im * z->im + i * step + -2.f ;
    z->im = 2 * temp * z->im + 2.f - j * step;
}

void mandelbrot(int x, int y, int color)
{   
    int n = 0;
    t_z z;
    int i = 0;
    int j = 0;
    void *mlx;
    mlx = mlx_init();
    void *win_ptr=mlx_new_window(mlx,x,y,"Mandelbrot set");
    while(j < y)
    {
        i = 0;
        while(i < x)
        {
            n = 0;
            z.re = 0;
            z.im = 0;
            while (n < 1000 && z.re * z.re + z.im * z.im <= 4)
            {   
               iterate(&z,step(-2.f, 2.f, 0, x),i,j);
                n++;
            }
            if (n <  1000)
                mlx_pixel_put(mlx,win_ptr,i,j,color*  255 * n);
            i++;
        }
        j++;
    }
    mlx_loop(mlx);
}