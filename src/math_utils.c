#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((unscaled_num - old_min) * (new_max - new_min) / (old_max - old_min) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.re = z1.re + z2.re;
	result.im = z1.im + z2.im;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.re = z.re * z.re - z.im * z.im;
	result.im = 2 * z.re * z.im;
	return (result);
}

t_complex	abs_complex(t_complex z)
{
	t_complex	result;

	result.re = fabs(z.re); 
	result.im = fabs(z.im);
	return (result);
}

int	get_psychedelic_color(int i, t_fractal *fractal)
{
	int		cross;

	if (fractal->iterations_definition == 0)
		return (COLORS[0]);
	
	cross = i * COLOR_COUNT / fractal->iterations_definition;
	return (COLORS[(cross + fractal->color_shift) % COLOR_COUNT]);
}
