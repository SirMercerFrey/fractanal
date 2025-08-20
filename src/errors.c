/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:59:28 by mcharret          #+#    #+#             */
/*   Updated: 2025/08/17 16:59:30 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error_and_exit(void)
{
	write(2, "Penitenziagite !!!\n", 19); 
	write(2, "Please enter one of the following:\n", 35);
	write(2, "\t\"./fractol mandelbrot\"\n", 24);
	write(2, "\t\"./fractol julia <value_1> <value_2>\"\n", 39);
	write(2, "\t\"./fractol burning_ship\"\n", 26);
	write(2, "Merci.exe\n", 10);
	exit(EXIT_FAILURE);
}

void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

int	is_valid_args(int argc, char **argv)
{
	return ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
		|| (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12)));
}
