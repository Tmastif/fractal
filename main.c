/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:20:37 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/09 22:08:12 by ilazar           ###   ########.fr       */
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

double  scale1(double unscaled, double new_min, double new_max, double old_max)
{
    double res;

    res = (new_max - new_min) * (unscaled - 0);
    return (res / (old_max - 0) + new_min);
}

int main(int ac, char **av)
{
    t_fractal  fractal;

    printf("%f  %f", ft_atodbl("-0.8"), ft_atodbl("0.156"));

    // if (ac == 2 || ac == 4)
    // {
    //     printf("%d", ac);
    //     if (ft_strcmp(av[1], "mandelbrot"))
    //         fractal.name = av[1];
    //     else if (ft_strcmp(av[1], "julia") && ac == 4)
    //     {
    //         printf("%f  %f", ft_atodbl(av[2]), ft_atodbl(av[3]));
    //         fractal.name = av[1];
    //         fractal.julia_x = ft_atodbl(av[2]);
    //         fractal.julia_y = ft_atodbl(av[3]);
    //     }
    //     else
    //         return (instructions(), 0);
    //     picture_init(&fractal);
    //     fractal_init(&fractal);
    //     events_init(&fractal);

        //fractal_render(&fractal);
    //     mlx_loop(fractal.mlx);
    // }
    return (0);
}

void    fractal_init(t_fractal *fractal)
{
    fractal->escape = 4;
    fractal->max_iterations = 256;
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;
    fractal->zoom = 1.0;
}

void    instructions()
{
    // ft_printf("Options are:\nmandelbrot\njulia <value1> <value2>\n
    //             + - change number of iterations\n
    //             left right up down arrows to move the grid\n
    //             mousewheel to zoom in and out");
    printf("Type:\n\"mandelbrot\"\nor\n\"julia <value1> <value2>\"\n\n\
        + - to change number of iterations\n\
        left - right - up - down arrows to move the grid\n\
        mousewheel to zoom in and out\n\
        ESC to exit\n");
}