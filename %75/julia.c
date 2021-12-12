#include "fractol.h"

static float iteratei(t_z z, t_z c)
{
    z.re = z.re * z.re - z.im * z.im + c.re;
    return (z.re);
}
static float iteratej(t_z z, t_z c,float temp)
{
    z.im = 2 * temp * z.im + c.im;
    return (z.im);
}

void julia(t_mlx *w)
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
            w->z.re = i * step(w->st1, w->st2, 0,w->x) + w->st1;
            w->z.im = w->st2 - j * step(w->st1, w->st2, 0, w->y);
            while (++n < 500 && w->z.re * w->z.re + w->z.im * w->z.im < 4)
            {
                temp = w->z.re;
                w->z.re = iteratei(w->z, w->c);
                w->z.im = iteratej(w->z,w->c,temp);
            }
            if (n < 500)
               buffer[(j * line_bytes) + i] = w->color * n;
            i++;
        }
        j++;
    }
    mlx_put_image_to_window(w->mlx,w->win,w->image,0,0);
}