/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:20:37 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/08 22:02:35 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void malloc_error()
{
    perror("Malloc error");
    exit(1);
}

void    picture_init(t_fractal *fractal)
{
    fractal->mlx = mlx_init();
    if (fractal->mlx == NULL)
        malloc_error();
    fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
    if (fractal->win == NULL)
        {
            mlx_destroy_display(fractal->mlx);
            free(fractal->mlx);
            malloc_error();
        }
    fractal->img.img_ptr = NULL; //in case exit window before loading img
    fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    if (fractal->img.img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx, fractal->win);
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        malloc_error();
    }
    fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
                                     &fractal->img.bits_per_pixel,
                                     &fractal->img.line_len,
                                     &fractal->img.endian);
}

int main(void)
{
    t_fractal  fractal;

    fractal.name = "Mandelbrot"; //av[1];

    picture_init(&fractal);

    events_init(&fractal);
    
    fractal.escape = 4;
    fractal.max_iterations = 256;
    
    fractal_render(&fractal);
    
    mlx_loop(fractal.mlx);

    

    return (0);
}