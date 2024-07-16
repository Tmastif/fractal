/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:21:41 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/15 19:09:55 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
//# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 600
# define HEIGHT 600
# define MALLOC_ERROR -1

typedef struct s_img
{
	void			*img_ptr;
	char			*pixel_ptr;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
}					t_img;

typedef struct s_fractal
{
	void			*mlx;
	void			*win;
	t_img			img;
	char			*name;
	double			escape;
	int				max_iterations;
	double			shift_x;
	double			shift_y;
	double			zoom;
	unsigned int	mandelbrot;
	double			julia_x;
	double			julia_y;
}					t_fractal;

typedef struct s_complex
{
	double			real;
	double			i;
}					t_complex;

void				instructions(void);

// events
void				events_init(t_fractal *fractal);
void				fractal_init(t_fractal *fractal);
void				picture_init(t_fractal *fractal);
void				init_julia(t_fractal *fractal, char *x, char *y);

// fractal render
void				fractal_render(t_fractal *fractal);

// renderin
int					encode_rgb(unsigned char red, unsigned char green,
						unsigned char blue);
void				img_pixel_put(t_img *img, int x, int y, int color);
double				scale(double unscaled, double new_min, double new_max,
						double old_max);

// error
void				malloc_error(void);
void				instructions(void);

// utils
double				ft_atodbl(char *str);

#endif
