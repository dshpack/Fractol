/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 21:10:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/11/20 16:38:50 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_menu_rectangle(t_windw *wind)
{
	int		x;
	int		y;
	int		x_max;
	int		y_max;

	y = 15;
	if (wind->evnt.menu_draw)
	{
		y_max = 372;
		x_max = 535;
	}
	else
	{
		y_max = 50;
		x_max = 260;
	}
	while (++y < y_max)
	{
		x = 9;
		while (++x <= x_max)
			set_px(wind, x, y, 0x000000);
	}
}

char		*write_curr_effect(t_windw *wind)
{
	if (wind->effect == 1)
		return ("Normal");
	if (wind->effect == 2)
		return ("Stars");
	if (wind->effect == 3)
		return ("Fat stars");
	if (wind->effect == 4)
		return ("Stained Glass");
	if (wind->effect == 5)
		return ("Black");
	if (wind->effect == 0)
		return ("Mistic");
	return (NULL);
}

char		*write_curr_fract(t_windw *wind)
{
	if (wind->selector == 1)
		return ("Mandelbrot");
	if (wind->selector == 2)
		return ("Celtic Mandelbrot");
	if (wind->selector == 3)
		return ("Heart Mandelbrot");
	if (wind->selector == 4)
		return ("Tricorn");
	if (wind->selector == 5)
		return ("Perpendicular Mandelbrot");
	if (wind->selector == 6)
		return ("Burning Ship");
	if (wind->selector == 7)
		return ("Perpendicular Burning Ship");
	if (wind->selector == 8)
		return ("Julia");
	if (wind->selector == 9)
		return ("Cubic Mandelbrot");
	if (wind->selector == 10)
		return ("Mandelbar 5th");
	return (NULL);
}

void		draw_menu_info_helper(t_windw *wind)
{
	int		x;
	int		x2;
	int		y;
	void	*mlx;
	void	*win;

	x = 20;
	x2 = 240;
	y = 40;
	mlx = wind->mlx_ptr;
	win = wind->win_ptr;
	mlx_string_put(mlx, win, x, y, 0x2471A3, "Current parameters:");
	mlx_string_put(mlx, win, x += 20, y += 20, 0x2471A3, "Fractal");
	mlx_string_put(mlx, win, x2, y, 0x00FF00, write_curr_fract(wind));
	if ((wind->evnt.iter_num = ft_itoa(wind->evnt.iter)))
		mlx_string_put(mlx, win, x2, y += 20, 0x00FF00, wind->evnt.iter_num);
	else
		mlx_string_put(mlx, win, 240, y, 0x00FF00, "can't calculate");
	ft_strdel(&wind->evnt.iter_num);
	mlx_string_put(mlx, win, x, y, 0x2471A3, "iterations:");
	mlx_string_put(mlx, win, x, y += 20, 0x2471A3, "effect:");
	mlx_string_put(mlx, win, x2, y, 0x00FF00, write_curr_effect(wind));
	mlx_string_put(mlx, win, x, y += 80, 0x2471A3, "change fractal:");
	mlx_string_put(mlx, win, x -= 20, y -= 20, 0x2471A3, "Actions:");
	mlx_string_put(mlx, win, x2, y + 20, 0xAED6F1, "1-2-3-4-5-6-7-8-9-0");
}

void		draw_menu_info(t_windw *wind)
{
	int		x;
	int		x2;
	int		y;
	void	*mlx;
	void	*win;

	draw_menu_info_helper(wind);
	draw_menu_end(wind);
	mlx = wind->mlx_ptr;
	win = wind->win_ptr;
	x = 40;
	x2 = 240;
	y = 180;
	mlx_string_put(mlx, win, x, y += 20, 0x2471A3, "scale fractal:");
	mlx_string_put(mlx, win, x2, y, 0xAED6F1, "+/-");
	mlx_string_put(mlx, win, x, y += 20, 0x2471A3, "iterations +/-:");
	mlx_string_put(mlx, win, x2, y, 0xAED6F1, "+/- (numpad)");
	mlx_string_put(mlx, win, x, y += 60, 0x2471A3, "move fractal:");
	mlx_string_put(mlx, win, x2, y, 0xAED6F1, "left-right-up-down");
	mlx_string_put(mlx, win, x, y += 20, 0x2471A3, "change effects:");
	mlx_string_put(mlx, win, x2, y, 0xAED6F1, "1-2-3-4-5-6 (numpad)");
	mlx_string_put(mlx, win, x, y += 20, 0x2471A3, "reset changes:");
	mlx_string_put(mlx, win, x2, y, 0xAED6F1, "Backspace");
	mlx_string_put(mlx, win, x, y += 20, 0x8B0000, "to escape:");
	mlx_string_put(mlx, win, x2, y, 0x8B0000, "ESC, or red cross");
}
