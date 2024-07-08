/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorgame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:21:43 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/08 19:40:31 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"



void    color_screen(t_fractal *fractal)
{
    int y;
    int x;
    int rgb;
    int color;
    int r = 0;
    int g = 230;
    int b = 0;
    
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            color = encode_rgb(r, g, b);
            //mlx_pixel_put(fractal->mlx, fractal->win, x, y, color);
            img_pixel_put(&fractal->img, x, y, color);
            r += 20;
            g += 10;
            b += 50;
            if (r > 235)
                r = 0;
             if (g > 252)
                g = 0;
             if (b > 230)
                b = 0;
            x++;
        }
        y++;
    }
}
void    background(t_fractal *fractal)
{
    int y;
    int x;
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            int color = encode_rgb(225,50,50);
            img_pixel_put(&fractal->img, x, y, color);
            x++;
        }
        y++;
    }
}