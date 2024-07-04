
#include "includes/fractol.h"

// int encode_rgb (unsigned char red ,unsigned char green ,unsigned char blue)
// {
//     return (red << 16 | green << 8 | blue);
// }

void    color_screen(t_vars *vars)
{
    int y;
    int x;
    int rgb;
    int color;
    int r = 0;
    int g = 230;
    int b = 0;
    
    y = 0;
    while (y < WINDOW_HEIGHT)
    {
        x = 0;
        while (x < WINDOW_WIDTH)
        {
            color = encode_rgb(r, g, b);
            //mlx_pixel_put(vars->mlx, vars->win, x, y, color);
            img_pixel_put(vars->mlx, x, y, color);
            //mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
            r += 20;
            g += 30;
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
void    background(t_vars *vars)
{
    int y;
    int x;
    y = 0;
    while (y < WINDOW_HEIGHT)
    {
        x = 0;
        while (x < WINDOW_WIDTH)
        {
            int color = encode_rgb(225,50,50);
            img_pixel_put(vars->mlx, x, y, color);
            x++;
        }
        y++;
    }
}