/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:26:53 by dshpack           #+#    #+#             */
/*   Updated: 2018/11/20 16:26:46 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	event_x(t_windw *wind)
{
	mlx_destroy_window(wind->mlx_ptr, wind->win_ptr);
	ptr_freashing(wind);
	exit(0);
}

static int	mouse_handler(int key, int x, int y, t_windw *wind)
{
	if (key == JULIA_LOCK && wind->selector == 8)
		wind->evnt.julia_lock = wind->evnt.julia_lock == 1 ? 0 : 1;
	if (key == 1)
	{
		wind->evnt.mouse_lock = wind->evnt.mouse_lock == 1 ? 0 : 1;
		mouse_pos(x, y, wind);
	}
	if (key == 4 || key == 5)
		change_zoom(key, wind->mrel, wind->mimg, wind);
	if (key == 6 || key == 7)
	{
		if (key == 7 && wind->threads_sum < 4)
			wind->threads_sum += 1;
		else if (key == 6 && wind->threads_sum - 1 > 0)
			wind->threads_sum += -1;
	}
	drawing(wind, wind->threads_sum);
	return (0);
}

static int	event_handler(int key, t_windw *wind)
{
	if (key == 49 && wind->selector == 8)
		mouse_handler(key, 0, 0, wind);
	if (key == 24 || key == 27 || key == 49 || key == 69 || key == 78 ||
		key == 18 || key == 19 || key == 20 || key == 21 || key == 22 ||
		key == 23 || key == 25 || key == 26 || key == 28 || key == 29 ||
		key == 14 || key == 1 || key == 2)
		rotating_and_scaling(key, wind);
	if (key == 116 || key == 121 || key == 124 || key == 123 || key == 126 ||
		key == 125 || key == 46 || key == 36 || key == 83 || key == 84 ||
		key == 85 || key == 86 || key == 87 || key == 88)
		menu_wmk_pushes(key, wind);
	if (key == 8)
		wind->color_iter = (wind->color_iter > 0) ? 0 : 1;
	if (key == 51 || key == ESCAPE)
		to_start(key, wind);
	drawing(wind, wind->threads_sum);
	return (0);
}

int			main(int argc, char **argv)
{
	int		fract_id;
	t_windw	*wind;

	fract_id = 0;
	if (argc > 1)
	{
		if (validation(argv[1]) == 1)
			print_error_and_close(1);
		fract_set(argv[1], &fract_id);
		wind = init_window();
		wind->selector = fract_id;
		drawing(wind, wind->threads_sum);
		mlx_hook(wind->win_ptr, 17, 1L << 17, event_x, wind);
		mlx_hook(wind->win_ptr, 2, 5, event_handler, wind);
		mlx_hook(wind->win_ptr, 6, 1L << 6, mouse_pos, wind);
		mlx_mouse_hook(wind->win_ptr, mouse_handler, wind);
		mlx_loop(wind->mlx_ptr);
	}
	else
		print_error_and_close(1);
	return (0);
}
