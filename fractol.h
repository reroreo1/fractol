#ifndef FRACTOL_H
#define FRACTOL_H

#include "mlx.h"
#include<math.h>

void mandelbrot(int x, int y, int color);
void julia(int x, int y, int color,t_z c);
typedef struct s_z
{
    double   re;
    double  im;
} t_z;
#endif