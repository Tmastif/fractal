/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:21:41 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/09 21:54:01 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

# define WIDTH 600
# define HEIGHT 600
# define MALLOC_ERROR -1

typedef struct s_img
{
    void    *img_ptr;
    char    *pixel_ptr; //points to the 1st pixel of the img
    int bits_per_pixel;
    int line_len; //the amount of bytes taken by one row of our image
                  // == image_width * (bpp / 8).
    int endian;
}               t_img;

typedef struct s_fractal
{
    void    *mlx;
    void    *win;
    t_img   img;
    char    *name;
    double  escape;
    int max_iterations;
    double shift_x;
    double shift_y;
    double  zoom;
    double julia_x;
    double julia_y;
}   t_fractal;

typedef struct  s_complex
{
    double  real;
    double  i;
}               t_complex;

void    instructions();

//events
void    events_init(t_fractal *fractal);
void    fractal_init(t_fractal *fractal);


//fractal render
void    fractal_render(t_fractal *fractal);


//renderin
int render(t_fractal *fractal);
int encode_rgb (unsigned char red ,unsigned char green ,unsigned char blue);
void   img_pixel_put(t_img *img, int x, int y, int color);

//error
void malloc_error();

//utils
double ft_atodbl(char *str);
int ft_strcmp(char *s1, char *s2);

# endif