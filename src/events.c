#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_plus || keysym == XK_KP_Add)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
		fractal->iterations_definition -= 10;
	else if (keysym == XK_c || keysym == XK_C)
		fractal->color_shift += 1;
	fractal_render(fractal);
	return (0);
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double zoom_factor;
	double mouse_re_before;
	double mouse_im_before;
	double mouse_re_after;
	double mouse_im_after;

	mouse_re_before = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	mouse_im_before = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	if (!ft_strncmp(fractal->name, "burning_ship", 12))
		mouse_im_before = (map(y, -2, 2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	if (button == Button4) 
		zoom_factor = 0.95;
	else if (button == Button5)
		zoom_factor = 1.05;
	fractal->zoom *= zoom_factor;
	mouse_re_after = (map(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	mouse_im_after = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	if (!ft_strncmp(fractal->name, "burning_ship", 12))
		mouse_im_after = (map(y, -2, 2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	fractal->shift_x -= (mouse_re_after - mouse_re_before);
	fractal->shift_y -= (mouse_im_after - mouse_im_before);
	fractal_render(fractal);
	return (0); 
}
