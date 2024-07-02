/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:20:37 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/02 17:57:02 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

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

static int handle_no_event(void)
{
    return (0);
}

static int on_keyRelease(int keysym, t_vars *vars)
{
    printf("keyrealesed: %d\n", keysym);
    if (keysym == XK_Escape)
        on_xclose(vars);
    return (0);
}

static int on_mouseRelease(int button, int x, int y, t_vars vars)
{
    printf("mouse button: %d\n", button);
    printf("x: %d\n", x);
    printf("y: %d\n", y);
    return (0);
}

static int on_xclose(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
    exit(1); //what is this?
    return (0);
}


int main(void)
{
    t_vars  vars;

    vars.mlx = mlx_init();
    if (vars.mlx == NULL)
        return (MLX_ERROR);
    vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "window1");
    if (vars.win == NULL)
        return (free(vars.mlx), MLX_ERROR);

    mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
    mlx_hook(vars.win, KeyRelease, KeyReleaseMask, &on_keyRelease, &vars);
    mlx_hook(vars.win, ButtonPress, ButtonPressMask, &on_mouseRelease, &vars);
    mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &on_xclose, &vars);


    mlx_loop(vars.mlx);

//    mlx_destroy_display(vars.mlx);
  //  free(vars.mlx);
    return (0);
}