/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:58:48 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/12 14:55:01 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	apply_formula(t_complex *z, t_complex *c);

// general formula: z = z^2 + c
static void	apply_formula(t_complex *z, t_complex *c)
{
	double	tmp_real;

	tmp_real = (z->real * z->real) - (z->i * z->i);
	z->i = 2 * z->real * z->i;
	z->real = tmp_real;
	z->real = z->real + c->real;
	z->i = z->i + c->i;
}

static void	which_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->real = fractal->julia_x;
		c->i = fractal->julia_y;
	}
	else
	{
		c->real = z->real;
		c->i = z->i;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			iterations;
	int			color;

	iterations = 0;
	z.real = (scale(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.i = (scale(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	which_fractal(&z, &c, fractal);
	while (iterations < fractal->max_iterations)
	{
		apply_formula(&z, &c);
		if ((z.real * z.real) + (z.i * z.i) > fractal->escape)
		{
			color = scale(iterations, encode_rgb(0, 0, 0), encode_rgb(225, 225,
						225), fractal->max_iterations);
			img_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		iterations++;
	}
	img_pixel_put(&fractal->img, x, y, encode_rgb(0, 0, 0));
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img_ptr, 0,
		0);
}
