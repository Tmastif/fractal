/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:09:24 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/12 15:10:52 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	on_keyrelease(int keysym, t_fractal *fractal);
static int	on_mouserelease(int button, int x, int y, t_fractal *fractal);
static int	on_xclose(t_fractal *fractal);
static int	clean_close(t_fractal *fractal);

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->win, KeyRelease, KeyReleaseMask, &on_keyrelease, fractal);
	mlx_hook(fractal->win, ButtonPress, ButtonPressMask, &on_mouserelease,
		fractal);
	mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask, &on_xclose,
		fractal);
}

static int	on_keyrelease(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		clean_close(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.3 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.3 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.3 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.3 * fractal->zoom);
	else if (keysym == XK_plus || keysym == XK_KP_Add || keysym == XK_equal)
		fractal->max_iterations += 10;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
		fractal->max_iterations -= 10;
	fractal_render(fractal);
	return (0);
}

static int	on_mouserelease(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button4)
		fractal->zoom *= 0.95;
	else if (button == Button5)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}

static int	on_xclose(t_fractal *fractal)
{
	return (clean_close(fractal), 0);
}

static int	clean_close(t_fractal *fractal)
{
	if (fractal->img.img_ptr != NULL)
		mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx, fractal->win);
	fractal->win = NULL;
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(1);
	return (0);
}
