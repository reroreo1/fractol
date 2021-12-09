#include "fractol.h"

static float step(float x, float y,float x1,float y1)
{
    float i;

    i = 0.f;
    i = (x - y) / (x1 - y1);
    return i;
}

static float iteratei(t_z z, float step, int i)
{
    z.re = z.re * z.re - z.im * z.im + i * step + -2.f;
    return(z.re);
}

static float iteratej(t_z z, float step, int j, float temp)
{
    z.im = 2 * temp * z.im + 2.f - j * step;
    return (z.im);
}
int quit()
{
    exit(1);
    return (1);
}

void mandelbrot(t_mlx *w)
{
    float temp;
    int n = 0;
    int i = 0;
    int j = 0;
    
    while(j < w->y)
    {
        i = 0;
        while(i < w->x)
        {
            n = 0;
            w->z.re = 0;
            w->z.im = 0;
            while (n < 1000 && w->z.re * w->z.re + w->z.im * w->z.im <= 4)
            {
                temp = w->z.re;    
                w->z.re = iteratei(w->z,step(w->st1, w->st2, 0, w->x),i);
                w->z.im = iteratej(w->z,step(w->st1, w->st2, 0, w->y),j,temp);
                n++; 
            }
            if (n < 1000)
                mlx_pixel_put(w->mlx,w->win,i,j,w->color * n);
            i++;
        }
        j++;
    }
}