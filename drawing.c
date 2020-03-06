/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:57:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/11/20 16:37:10 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		break_effects(t_windw *w, t_comp *c)
{
	if ((w->effect == 0 && c->tmp_r * c->tmp_r + c->tmp_i * c->tmp_i > 4)
	|| (w->effect == 1 && c->tmp_r * c->tmp_r + c->tmp_i * c->tmp_i > 4)
	|| (w->effect == 2 && c->tmp_r * c->tmp_r * c->tmp_i * c->tmp_i > 4)
	|| (w->effect == 3 && c->tmp_r / 250 * c->tmp_r * c->tmp_i * c->tmp_i > 4)
	|| (w->effect == 4 && c->tmp_r * c->tmp_r - c->tmp_i * c->tmp_i > 4)
	|| (w->effect == 5 && -c->tmp_r / 0.2 * c->tmp_r + c->tmp_i + c->tmp_i > 4))
		return (1);
	return (0);
}

static void		fractal_selector(t_windw *w, t_comp *c)
{
	void	(*func)(t_comp *);

	if ((w->selector == 1 && (func = &mandelbrot))
	|| (w->selector == 2 && (func = &celtic_mandelbrot))
	|| (w->selector == 3 && (func = &heart_mandelbrot))
	|| (w->selector == 4 && (func = &tricorn))
	|| (w->selector == 5 && (func = &perpen_mandelbrot))
	|| (w->selector == 6 && (func = &burning_ship))
	|| (w->selector == 7 && (func = &perpen_burning_ship))
	|| (w->selector == 9 && (func = &cubic_mandelbrot))
	|| (w->selector == 10 && (func = &mandelbar_5th)))
		func(c);
	if (w->selector == 8)
		julia(w, c);
}

static int		fr_get(t_windw *w, t_comp *c)
{
	int		i;

	c->tmp_r = c->correctiv_x;
	c->tmp_i = c->correctiv_y;
	i = -1;
	while (++i < w->evnt.iter)
	{
		c->real_num = c->tmp_r;
		c->imagin_num = c->tmp_i;
		fractal_selector(w, c);
		if (break_effects(w, c))
			break ;
	}
	return (i);
}

static void		*draw_fract(void *extract)
{
	int		y;
	int		x;
	t_windw	*w;
	t_comp	comp;

	w = ((t_thread *)extract)->wind;
	comp.thread_id = (int)(((t_thread *)extract)->id);
	y = -comp.thread_id;
	comp.cofx = ((w->fract.remax - w->fract.remin) / w->width);
	comp.cofy = ((w->fract.immax - w->fract.immin) / w->height);
	comp.correctiv_y = w->fract.immin + comp.cofy + w->evnt.move_y;
	while (y + comp.thread_id < w->height && (x = -1))
	{
		comp.correctiv_x = w->fract.remin + w->evnt.move_x;
		while (++x < w->width)
		{
			set_px(w, x, y + comp.thread_id, (w->color_iter == 0) ?
				(0xffffffff / w->evnt.iter) * fr_get(w, &comp)
				: w->c * w->c * get_col(fr_get(w, &comp), w->evnt.iter));
			comp.correctiv_x += comp.cofx;
		}
		y += w->threads_sum - comp.thread_id;
		comp.correctiv_y += comp.cofy;
	}
	return (NULL);
}

void			drawing(t_windw *wind, size_t threads_sum)
{
	size_t		id;
	t_thread	data[threads_sum];
	pthread_t	threads_arr[threads_sum];

	if (!wind && threads_sum < 1)
		return ;
	id = -1;
	while (++id < threads_sum)
	{
		data[id].wind = wind;
		data[id].id = id;
		pthread_create(&threads_arr[id], NULL, draw_fract, &data[id]);
	}
	id = -1;
	while (++id < threads_sum)
		pthread_join(threads_arr[id], NULL);
	if (wind->effect > 0)
		mlx_clear_window(wind->mlx_ptr, wind->win_ptr);
	draw_menu_rectangle(wind);
	mlx_put_image_to_window(wind->mlx_ptr, wind->win_ptr, wind->img_ptr, 0, 0);
	if (wind->evnt.menu_draw)
		draw_menu_info(wind);
	mlx_string_put(wind->mlx_ptr, wind->win_ptr, 20, 20, 0xFF4500,
			"MENU ON/OFF:");
	mlx_string_put(wind->mlx_ptr, wind->win_ptr, 240, 20, 0xFF4500, "m");
}
