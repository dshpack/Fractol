/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:55:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/11/20 16:35:59 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		rotating_and_scaling(int key, t_windw *wind)
{
	int		id;

	if ((key == MANDELBROT_SELECT && (id = 1))
	|| (key == CELTIC_SELECT && (id = 2))
	|| (key == HEART_MAN_SELECT && (id = 3))
	|| (key == TRICORN_SELECT && (id = 4))
	|| (key == PERPEN_MAN_SELECT && (id = 5))
	|| (key == SHIP_SELECT && (id = 6))
	|| (key == PERPEN_SHIP_SELECT && (id = 7))
	|| (key == JULIA_SELECT && (id = 8))
	|| (key == CUBIC_SELECT && (id = 9))
	|| (key == MANDELBAR_5TH && (id = 10)))
		wind->selector = id;
	if (key == SCALE_PLUS || key == SCALE_MINUS)
	{
		wind->evnt.scale = (key > 24) ? -1 : 1;
		change_zoom(key, wind->mrel, wind->mimg, wind);
		wind->evnt.scale = 0;
	}
	if (key == ITER_PLUS && wind->evnt.iter < MAX_INT)
		wind->evnt.iter += 1;
	if (key == ITER_MINUS && wind->evnt.iter > 1)
		wind->evnt.iter -= 1;
}

void		menu_wmk_pushes(int key, t_windw *w)
{
	if (key == COLOR_PLUS || key == COLOR_MINUS)
		if ((w->c + 385 >= 0 || w->c - 385 <= MAX_INT) || w->c - 385 >= 0)
			w->c += (key > 116) ? -385 : 385;
	if (key == MOVE_X_TO_LEFT)
		w->evnt.move_x += 0.5;
	if (key == MOVE_X_TO_RIGHT)
		w->evnt.move_x -= 0.5;
	if (key == MOVE_Y_TO_TOP)
		w->evnt.move_y += 0.5;
	if (key == MOVE_Y_TO_BOTTOM)
		w->evnt.move_y -= 0.5;
	if (key == EF_NORMAL)
		w->effect = 1;
	if (key == EF_STARS)
		w->effect = 2;
	if (key == EF_FAT_STARS)
		w->effect = 3;
	if (key == EF_STAINED_GLASS)
		w->effect = 4;
	if (key == EF_BLACK)
		w->effect = 5;
	if (key == EF_MISTIC)
		w->effect = 0;
	if (key == MENU_DRAW)
		w->evnt.menu_draw = (w->evnt.menu_draw == 0) ? 1 : 0;
}

void		to_start(int key, t_windw *wind)
{
	if (key == BACK_TO_START)
	{
		set_fract_limits(wind);
		wind->threads_sum = 4;
		wind->evnt.move_x = 0;
		wind->evnt.move_y = 0;
		wind->evnt.scale = 0.2;
		wind->evnt.iter = 70;
		wind->color_iter = 0;
		wind->effect = 1;
	}
	if (key == ESCAPE)
	{
		mlx_destroy_window(wind->mlx_ptr, wind->win_ptr);
		ptr_freashing(wind);
		exit(0);
	}
}

int			mouse_pos(int x, int y, t_windw *wind)
{
	wind->mrel = x / (wind->width / (wind->fract.remax - wind->fract.remin))
				+ wind->fract.remin;
	wind->mimg = y / (wind->height / (wind->fract.immax - wind->fract.immin))
				+ wind->fract.immin;
	if (wind->evnt.mouse_lock == 0
	&& wind->evnt.julia_lock == 0
	&& wind->selector == 8 && x >= 0
	&& y >= 0 && x < wind->width && y < wind->height)
	{
		wind->mouse_x = .27015 + (x - (float)wind->width / 2) * 5 / wind->width;
		wind->mouse_y = -.7 + (y - (float)wind->height / 2) * 5 / wind->height;
		drawing(wind, wind->threads_sum);
	}
	else if (wind->evnt.mouse_lock == 1
	&& x >= 0 && y >= 0 && x < wind->width && y < wind->height)
	{
		wind->evnt.move_x =
				-(0.27015 + (x - (double)wind->width / 2) * 5 / wind->width);
		wind->evnt.move_y =
				-(0.7 + (y - (double)wind->height / 2) * 5 / wind->height);
		drawing(wind, wind->threads_sum);
	}
	return (0);
}

void		change_zoom(int key, double x, double y, t_windw *wind)
{
	double zoomer;
	double interpolation;

	zoomer = 1;
	if ((key == 4 || wind->evnt.scale == 1) && wind->evnt.zoom_sum < 80)
	{
		zoomer = 1.5;
		wind->evnt.zoom_sum += 1;
	}
	else if ((key == 5 || wind->evnt.scale == -1) && wind->evnt.zoom_sum > 0)
	{
		zoomer = 0.5;
		wind->evnt.zoom_sum -= 1;
	}
	interpolation = 1.0 / zoomer;
	wind->fract.remax = x + ((wind->fract.remax - x) * interpolation);
	wind->fract.remin = x + ((wind->fract.remin - x) * interpolation);
	wind->fract.immin = y + ((wind->fract.immin - y) * interpolation);
	wind->fract.immax = y + ((wind->fract.immax - y) * interpolation);
}
