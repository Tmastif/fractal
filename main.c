/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:20:37 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/04 19:15:08 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static int handle_no_event(void)
{
    return (0);
}

int encode_rgb (unsigned char red ,unsigned char green ,unsigned char blue)
{
    return (red << 16 | green << 8 | blue);
}

void   img_pixel_put(t_img *img, int x, int y, int color)
{
    int pixel;

    pixel = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
    *((unsigned int *)(pixel + img->img_pixel_ptr)) = color;
}

static int render(t_vars *vars)
{
    if (vars->win != NULL)
    {
        color_screen(vars);
        //background(vars);
        // mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
    }
    //render_rect(vars, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, 0xFF0000});
    // if (vars->win != NULL)
    //     mlx_pixel_put(vars->mlx, vars->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0xFFFFFF);
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
static int close(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    vars->win = NULL;
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
    exit(1); //what is this?
    return (0);
}

static int on_xclose(t_vars *vars)
{
    close(vars);
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
    
    vars.img.img_ptr = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    vars.img.img_pixel_ptr = mlx_get_data_addr(vars.img.img_ptr,
                                    &vars.img.bits_per_pixel,
                                    &vars.img.line_len,
                                    &vars.img.endian);

    mlx_loop_hook(vars.mlx, &render, &vars);
    mlx_hook(vars.win, KeyRelease, KeyReleaseMask, &on_keyRelease, &vars);
    mlx_hook(vars.win, ButtonPress, ButtonPressMask, &on_mouseRelease, &vars);
    mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &on_xclose, &vars);

    mlx_loop(vars.mlx);

    //mlx_destroy_display(vars.mlx);
    //free(vars.mlx);
    return (0);
}