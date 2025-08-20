/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:59:37 by mcharret          #+#    #+#             */
/*   Updated: 2025/08/17 16:59:38 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double number, double new_min, double new_max, double old_max)
{
	return (number * (new_max - new_min) / old_max + new_min);
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
	int							cross;
	static const unsigned int	colors[COLOR_COUNT] = {
		ROUGE,
		ROUGE_ORANGE,
		ORANGE,
		JAUNE_ORANGE,
		JAUNE,
		JAUNE_VERT,
		VERT_CLAIR,
		VERT_CITRON,
		VERT_PUR,
		TURQUOISE,
		CYAN,
		BLEU_CLAIR,	
		BLEU_VIF,
		BLEU_PUR,
		VIOLET,
		MAGENTA,		
		ROSE
	};

	if (fractal->iterations_definition == 0)
		return (colors[0]);
	cross = i * COLOR_COUNT / fractal->iterations_definition;
	return (colors[(cross + fractal->color_shift) % COLOR_COUNT]);
}
