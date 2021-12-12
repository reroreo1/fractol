#include "fractol.h"

float step(float x, float y,float x1,float y1)
{
    float i;

    i = 0.f;
    i = (x - y) / (x1 - y1);
    return i;
}

static float iteratei(t_z z, float step, int i, float st1)
{
    z.re = z.re * z.re - z.im * z.im + i * step + st1;
    return(z.re);
}

static float iteratej(t_z z, float step, int j, float temp)
{
    z.im = 2 * temp * z.im - j * step;
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
            while (++n < 100 && w->z.re * w->z.re + w->z.im * w->z.im < 4)
            {
                temp = w->z.re;    
                w->z.re = iteratei(w->z,step(w->st1, w->st2, 0, w->x),i,w->st1);
                w->z.im = iteratej(w->z,step(w->st1, w->st2, 0, w->y),j,temp) + w->st2;
            }
            if (n < 100)
                buffer[(j * line_bytes) + i] = w->color * n;
            i++;
        }
        j++;
    }
    mlx_put_image_to_window(w->mlx, w->win, w->image, 0, 0);
}