#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_x> <value_y>\"\n or \n\t ./fractol burning_ship\"\n"
# define ERROR_JULIA "Please enter valid numbers \n\t\".fractol julia <value_x> <value_y>\"\n"

# define WIDTH	512
# define HEIGHT	512

# define BLACK	0x000000

# define MAGENTA_BURST		0xFF00FF
# define LIME_SHOCK			0xCCFF00
# define NEON_ORANGE		0xFF6600
# define PSYCHEDELIC_PURPLE	0x660066
# define AQUA_DREAM			0x33CCCC
# define HOT_PINK			0xFF66B2
# define ELECTRIC_BLUE		0x0066FF
# define LAVA_RED			0xFF3300

typedef enum
{
	COLOR_MAGENTA_BURST,
	COLOR_LIME_SHOCK,
	COLOR_NEON_ORANGE,
	COLOR_PSYCHEDELIC_PURPLE,
	COLOR_AQUA_DREAM,
	COLOR_HOT_PINK,
	COLOR_ELECTRIC_BLUE,
	COLOR_LAVA_RED,
	COLOR_COUNT
} ColorIndex;

static const unsigned int COLORS[COLOR_COUNT]=
{
	MAGENTA_BURST,
	LIME_SHOCK,
	NEON_ORANGE,
	PSYCHEDELIC_PURPLE,
	AQUA_DREAM,
	HOT_PINK,
	ELECTRIC_BLUE,
	LAVA_RED
};

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
t_complex   abs_complex(t_complex z);
int get_psychedelic_color(int i, t_fractal *fractal);
int ft_strlen(char *str);
int ft_strncmp(const char *s1, const char *s2, int n);
void    ft_putstr_fd(char *s, int fd);
int is_valid_double(char *s);
double  atodbl(char *s);

#endif
