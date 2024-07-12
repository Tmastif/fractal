/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:55:36 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/12 14:56:56 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
((new_max - new_min) * (unscaled_num - old_min)) / (old_max - old_min)
	+ new_min
*/
double	scale(double unscaled, double new_min, double new_max, double old_max)
{
	double	res;

	res = (new_max - new_min) * (unscaled - 0);
	return (res / (old_max - 0) + new_min);
}

int	encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	int	pixel;

	pixel = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(pixel + img->pixel_ptr)) = color;
}
