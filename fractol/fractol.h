#ifndef FRACTOL_H
#define FRACTOL_H

#include "mlx.h"
#include<math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct s_z
{
    float   re;
    float  im;
} t_z;

typedef struct s_mlx
{
    void   *mlx;
    void   *win;
    int x;
    int y;
    float   st1;
    float   st2;
    t_z z;
    float color;
    t_z c;
    int     is_julia;
} t_mlx;

void mandelbrot(t_mlx *w);
void julia(t_mlx *w);
int	ft_atoi(const char *str);
char *ft_strchr(const char *s, int c);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strdup(const char *str);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlen(const char *s);
char *ft_substr(char const *s, unsigned int start, size_t len);
float ft_itof(const char *num);
int	ft_isdigit(char *c);
char *nopoint(const char *num);
int quit();
int func(int k, t_mlx *w);


#endif