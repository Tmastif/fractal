/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:14:39 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/12 15:25:25 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	perror("Malloc error");
	exit(1);
}

void	instructions(void)
{
	ft_printf("Please chose between:\n\"mandelbrot\"\n");
	ft_printf("or\n\"julia <value1> <value2>\"\n\n+ - keys to change ");
	ft_printf("number of iterations\nLeft Right Up Down arrows to move\n");
	ft_printf("Mouse wheel to zoom in and out\nESC to exit\n");
}
