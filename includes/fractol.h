/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:21:41 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/04 18:27:05 by ilazar           ###   ########.fr       */
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

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define MLX_ERROR -1

typedef struct s_rect
{
    int x;
    int y;
    int width;
    int height;
    int color;
}   t_rect;

typedef struct s_img
{
    void    *img_ptr;
    char    *img_pixel_ptr;
    int bits_per_pixel;
    int line_len; //the amount of bytes taken by one row of our image
                  // == image_width * (bpp / 8).
    int endian;
}               t_img;

typedef struct s_vars
{
    void    *mlx;
    void    *win;
    t_img   img;
}   t_vars;

typedef struct  s_complex
{
    double  real;
    double  i;
}               t_complex;

//img
int encode_rgb (unsigned char red ,unsigned char green ,unsigned char blue);
void   img_pixel_put(t_img *img, int x, int y, int color);

//close
static int on_xclose(t_vars *vars);
static int close(t_vars *vars);


//delete me
int  render_rect(t_vars *vars, t_rect rect);
void    color_screen(t_vars *vars);

# endif