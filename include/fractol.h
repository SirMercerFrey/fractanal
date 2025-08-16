#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_x> <value_y>\"\n or \n\t ./fractol burning_ship\""
# define ERROR_JULIA "Please enter valid numbers \n\t\".fractol julia <value_x> <value_y>\""

# define WIDTH	512
# define HEIGHT	512

# define BLACK	0x000000

typedef struct	s_complex
{
	double	re;
	double	im;
} t_complex;

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
} t_img;

typedef struct	s_fractal
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
} t_fractal;

void    calculate_mandelbrot(int x, int y, t_fractal *fractal);
void    calculate_julia(int x, int y, t_fractal *fractal);
void    calculate_burning_ship(int x, int y, t_fractal *fractal);
void    my_pixel_put(int x, int y, t_img *img, int color);
void    handle_pixel(int x, int y, t_fractal *fractal);
void    fractal_render(t_fractal *fractal);
int close_handler(t_fractal *fractal);
int key_handler(int keysym, t_fractal *fractal);
int mouse_handler(int button, int x, int y, t_fractal *fractal);
void    malloc_error(void);
void    data_init(t_fractal *fractal);
void    events_init(t_fractal *fractal);
void    fractal_init(t_fractal *fractal);
double  map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex   sum_complex(t_complex z1, t_complex z2);
t_complex   square_complex(t_complex z);
t_complex   abs_square_complex(t_complex z);
int get_psychedelic_color(int i, t_fractal *fractal);
int ft_strlen(char *str);
int ft_strncmp(const char *s1, const char *s2, int n);
void    ft_putstr_fd(char *s, int fd);
int is_valid_double(char *s);
double  atodbl(char *s);

#endif
