/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:58:49 by mcharret          #+#    #+#             */
/*   Updated: 2025/08/17 16:58:51 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"

# define ERROR_MESSAGE	"Please enter a valid fractal name.\n" 
# define ERROR_JULIA "Please enter valid numbers.\n"

# define WIDTH	700
# define HEIGHT	700

# define BLACK	0x000000

# define ROUGE			0xFF0000
# define ROUGE_ORANGE	0xFF4000
# define ORANGE			0xFF8000
# define JAUNE_ORANGE	0xFFBF00
# define JAUNE			0xFFFF00
# define JAUNE_VERT		0xBFFF00
# define VERT_CLAIR		0x80FF00
# define VERT_CITRON	0x40FF00
# define VERT_PUR		0x00FF00
# define TURQUOISE		0x00FF80
# define CYAN			0x00FFFF
# define BLEU_CLAIR		0x00BFFF
# define BLEU_VIF		0x0080FF
# define BLEU_PUR		0x0000FF
# define VIOLET			0x8000FF
# define MAGENTA		0xBF00FF
# define ROSE			0xFF00FF

typedef enum e_color_index
{
	COLOR_ROUGE,
	COLOR_ROUGE_ORANGE,
	COLOR_ORANGE,
	COLOR_JAUNE_ORANGE,
	COLOR_JAUNE,
	COLOR_JAUNE_VERT,
	COLOR_VERT_CLAIR,
	COLOR_VERT_CITRON,
	COLOR_VERT_PUR,
	COLOR_TURQUOISE,
	COLOR_CYAN,
	COLOR_BLEU_CLAIR,	
	COLOR_BLEU_VIF,
	COLOR_BLEU_PUR,
	COLOR_VIOLET,
	COLOR_MAGENTA,		
	COLOR_ROSE,	
	COLOR_COUNT
}	t_color_index;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	int		color_shift;
	double	julia_x;
	double	julia_y;
}	t_fractal;

void		calculate_mandelbrot(int x, int y, t_fractal *fractal);
void		calculate_julia(int x, int y, t_fractal *fractal);
void		calculate_burning_ship(int x, int y, t_fractal *fractal);
void		my_pixel_put(int x, int y, t_img *img, int color);
void		handle_pixel(int x, int y, t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
void		malloc_error(void);
void		data_init(t_fractal *fractal);
void		events_init(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);
double		map(double number, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
t_complex	abs_complex(t_complex z);
int			get_psychedelic_color(int i, t_fractal *fractal);
int			ft_strlen(char *str);
int			ft_strncmp(const char *s1, const char *s2, int n);
void		ft_putstr_fd(char *s, int fd);
int			is_valid_double(char *s);
double		atodbl(char *s);
void		print_error_and_exit(void);
int			is_valid_args(int argc, char **argv);
void		init_julia(t_fractal *f, char **argv);
int			special_key_handler(int keysym, t_fractal *fractal);

#endif
