/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:20:37 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/12 15:25:40 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 || ac == 4)
	{
		if (!ft_strncmp(av[1], "mandelbrot", 10))
			fractal.name = av[1];
		else if (!ft_strncmp(av[1], "julia", 5) && ac == 4)
		{
			fractal.name = av[1];
			fractal.julia_x = ft_atodbl(av[2]);
			fractal.julia_y = ft_atodbl(av[3]);
		}
		else
			return (instructions(), 0);
		picture_init(&fractal);
		fractal_init(&fractal);
		events_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
		instructions();
	return (0);
}

void	picture_init(t_fractal *fractal)
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
	fractal->img.img_ptr = NULL;
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_len,
			&fractal->img.endian);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->escape = 4;
	fractal->max_iterations = 256;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}
