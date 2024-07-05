/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:58:48 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/05 18:16:59 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

/*
Mandelbrot
z = z^2 + c
z is 0, 0
c is the point to check
*/

static void    handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    double  tmp_real;
    int iterations;
    int color;

    iterations = 0;
    z.real = 0.0;
    z.i = 0.0;
    c.real = scale(x, -2, 2, WIDTH); // height width - 1 ?
    c.i = scale(y, 2, -2, HEIGHT);
    while (iterations < fractal->max_iterations) //number of iteration wanted
    {
        //general formula: z = z^2 + c
        //z^2
        tmp_real = (z.real * z.real) - (z.i * z.i);
        z.i = 2 * z.real * z.i;
        z.real = tmp_real;
        // + c
        z.real = z.real + c.real;
        z.i = z.i + c.i;
        if ((z.real * z.real) + (z.i * z.i) > fractal->escape) //value escaping range
        {
            color = scale(iterations, encode_rgb(0, 0, 0), encode_rgb(225, 225, 225), fractal->max_iterations);
            img_pixel_put(&fractal->img, x, y, color); //put pixel
            return ;
        }
        iterations++;
    }
    img_pixel_put(&fractal->img, x, y, encode_rgb(20, 20 ,20));
}

void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = 0; //-1
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            handle_pixel(x, y, fractal);
        }
    }
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img_ptr, 0, 0);
}

void    fractol()
{
    t_complex   z;
    t_complex   c;
    double  tmp_real;
    int count;

    z.real = 0;
    z.i = 0;
    
    c.real = 0.25;
    c.i = 0.4;
    count = 0;
    while (count < 10)
    {
        // general formula: z = z^2 + c
        tmp_real = (z.real * z.real) - (z.i * z.i);
        z.i = 2 * z.real * z.i;
        z.real = tmp_real;
        // + c
        z.real = z.real + c.real;
        z.i = z.i + c.i;
        count++;
        printf("iteration: %d real: %f imaginary: %f\n", count, z.real, z.i);
    }
}