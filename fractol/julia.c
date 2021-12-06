#include "fractol.h"

static float step(float x, float y,float x1,float y1)
{
    float i;

    i = 0.f;
    i = (x - y) / (x1 - y1);
    return i;
}
static void iterate(t_z *z, t_z c)
{
    float temp = z->re;
    z->re = z->re * z->re - z->im * z->im + c.re;
    z->im = 2 * temp * z->im + c.im;
}

void julia(int x, int y, int color,t_z c)
{   
    int n = 0;
    t_z z;
    int i = 0;
    int j = 0;
    void *mlx;
    mlx = mlx_init();
    void *win_ptr=mlx_new_window(mlx,x,y,"Julia set");
    while(j < y)
    {
        i = 0;
        while(i < x)
        {
            n = 0;
            z.re = i * step(2.f, -2.f, x, 0) + -2.f;
            z.im = 2.f - j * step(2.f, -2.f, y, 0);
            while (n < 1000 && z.re * z.re + z.im * z.im <= 4)
            {   
               iterate(&z,c);
                n++;
            }
            if (n < 1000)
                mlx_pixel_put(mlx,win_ptr,i,j,color * 10 * n);
            i++;
        }
        j++;
    }
    mlx_loop(mlx);
}