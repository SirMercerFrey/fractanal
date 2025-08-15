#include "fractal.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	char *dst;

	dst = img->pixels_ptr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	if (!strncmp(fractal->name, "mandelbrot", 10)
		calculate_mandelbrot(x, y, fractal);
	else if(!strncmp(fractal->name, "julia", 5)
		calculate_julia(x, y, fractal);
	else if (!strncmp(fractal->name, "burning_ship", 12)
		calculate_burning_ship(x, y, fractal);
}

void	fractal_render(t_fractal *fractal)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fracatl->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
