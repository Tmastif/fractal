
#include "includes/fractol.h"


int  render_rect(t_vars *vars, t_rect rect)
{
    int i;
    int j;

    if (vars->win == NULL)
        return (1);
    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            mlx_pixel_put(vars->mlx, vars->win, j++, i, rect.color);
        i++;
    }
    return (0);
}