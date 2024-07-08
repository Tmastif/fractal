/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:22:37 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/08 19:45:40 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int encode_rgb (unsigned char red ,unsigned char green ,unsigned char blue)
{
    return (red << 16 | green << 8 | blue);
}

void   img_pixel_put(t_img *img, int x, int y, int color)
{
    int pixel;

    pixel = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
    *((unsigned int *)(pixel + img->pixel_ptr)) = color;
}



int render(t_fractal *fractal)
{
    if (fractal->win != NULL)
    {
        //fractal_render(fractal);
        // background(fractal);
        color_screen(fractal);
        mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img_ptr, 0, 0);
    }
    return (0);
}
double  scale(double unscaled, double new_min, double new_max, double old_max)
{
    double res;

    res = (new_max - new_min) * (unscaled - 0);
    return (res / (old_max - 0) + new_min);
}
    // int i;

    // i = 0;
    // while (i < 100)
    // {
    //         printf("%d -> %f\n", i, scale(i, 0, 5, 0, 99));
    //         i++;
    // }
