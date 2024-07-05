/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:09:24 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/05 18:08:43 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static int on_keyRelease(int keysym, t_fractal *fractal);
static int on_mouseRelease(int button, int x, int y, t_fractal *fractal);
static int on_xclose(t_fractal *fractal);
static int clean_close(t_fractal *fractal);

void    events_init(t_fractal *fractal)
{
    mlx_loop_hook(fractal->mlx, &render, fractal);
    mlx_hook(fractal->win, KeyRelease, KeyReleaseMask, &on_keyRelease, fractal);
    mlx_hook(fractal->win, ButtonPress, ButtonPressMask, &on_mouseRelease, fractal);
    mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask, &on_xclose, fractal);
    mlx_loop(fractal->mlx);
}
static int on_keyRelease(int keysym, t_fractal *fractal)
{
    printf("keyrealesed: %d\n", keysym);
    if (keysym == XK_Escape)
        on_xclose(fractal);
    return (0);
}
static int on_mouseRelease(int button, int x, int y, t_fractal *fractal)
{
    printf("mouse button: %d\n", button);
    printf("x: %d\n", x);
    printf("y: %d\n", y);
    return (0);
}
static int on_xclose(t_fractal *fractal)
{
    clean_close(fractal);
    return (0);
}
static int clean_close(t_fractal *fractal)
{
    if (fractal->img.img_ptr != NULL)
        mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx, fractal->win);
    fractal->win = NULL;
    mlx_destroy_display(fractal->mlx);
    free(fractal->mlx);
    exit(1); //what is this?
    return (0);
}