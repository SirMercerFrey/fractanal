/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:59:21 by mcharret          #+#    #+#             */
/*   Updated: 2025/08/17 16:59:23 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_fractal *f, char **argv)
{
	if (!is_valid_double(argv[2]) || !is_valid_double(argv[3]))
	{
		ft_putstr_fd(ERROR_JULIA, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	f->julia_x = atodbl(argv[2]);
	f->julia_y = atodbl(argv[3]);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->color_shift = 0;
}

void	events_init(t_fractal *fractal)
{
	void	*win;

	win = fractal->mlx_window;
	mlx_hook(win, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(win, ButtonPress, ButtonPressMask, mouse_handler, fractal);
	mlx_hook(win, DestroyNotify, StructureNotifyMask, close_handler, fractal);
}

void	fractal_init(t_fractal *f)
{
	f->mlx_connection = mlx_init();
	if (NULL == f->mlx_connection)
		malloc_error();
	f->mlx_window = mlx_new_window(f->mlx_connection, WIDTH, HEIGHT, f->name);
	if (NULL == f->mlx_window)
	{
		mlx_destroy_display(f->mlx_connection);
		free(f->mlx_connection);
		malloc_error();
	}
	f->img.img_ptr = mlx_new_image(f->mlx_connection, WIDTH, HEIGHT);
	if (NULL == f->img.img_ptr)
	{
		mlx_destroy_window(f->mlx_connection, f->mlx_window);
		mlx_destroy_display(f->mlx_connection);
		free(f->mlx_connection);
		malloc_error();
	}
	f->img.pixels_ptr = mlx_get_data_addr(
			f->img.img_ptr,
			&f->img.bpp,
			&f->img.line_len,
			&f->img.endian);
	events_init(f);
	data_init(f);
}
