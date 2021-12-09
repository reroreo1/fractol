#include "fractol.h"

static float step(float x, float y,float x1,float y1)
{
    float i;

    i = 0.f;
    i = (x - y) / (x1 - y1);
    return i;
}
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

    while(j < w->y)
    {
        i = 0;
        while(i < w->x)
        {
            n = 0;
            w->z.re = i * step(w->st1, w->st2, 0,w->x) + w->st1;
            w->z.im = w->st2 - j * step(w->st1, w->st2, 0, w->y);
            while (n < 1000 && w->z.re * w->z.re + w->z.im * w->z.im <= 4)
            {
                temp = w->z.re;
                w->z.re = iteratei(w->z, w->c);
                w->z.im = iteratej(w->z,w->c,temp);
                n++;
            }
            if (n < 1000)
                mlx_pixel_put(w->mlx, w->win, i, j, w->color * cos(n));
            i++;
        }
        j++;
    }
}