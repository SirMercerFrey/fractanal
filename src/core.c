/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:59:05 by mcharret          #+#    #+#             */
/*   Updated: 2025/08/17 16:59:06 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.re = 0;
	z.im = 0;
	c.re = (map(x, -2.1, 1.1, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.im = (map(y, 1.65, -1.65, HEIGHT) * fractal->zoom) + fractal->shift_y;
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.re * z.re) + (z.im * z.im) > fractal->escape_value)
		{
			color = get_psychedelic_color(i, fractal);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	calculate_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.re = (map(x, -2.1, 1.1, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.im = (map(y, 1.65, -1.65, HEIGHT) * fractal->zoom) + fractal->shift_y;
	c.re = fractal->julia_x;
	c.im = fractal->julia_y;
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.re * z.re) + (z.im * z.im) > fractal->escape_value)
		{
			color = get_psychedelic_color(i, fractal);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	calculate_burning_ship(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.re = 0;
	z.im = 0;
	c.re = (map(x, -2.1, 1.1, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.im = (map(y, -1.65, 1.65, HEIGHT) * fractal->zoom) + fractal->shift_y;
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(abs_complex(z)), c);
		if ((z.re * z.re) + (z.im * z.im) > fractal->escape_value)
		{
			color = get_psychedelic_color(i, fractal);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}
