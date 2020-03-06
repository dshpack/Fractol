/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <dshpack@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:26:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/11/20 18:26:00 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_menu_helper2(t_windw *wind)
{
	int		x;
	int		x2;
	int		y;
	void	*mlx;
	void	*win;

	mlx = wind->mlx_ptr;
	win = wind->win_ptr;
	x = 40;
	x2 = 240;
	y = 220;
	mlx_string_put(mlx, win, x, y += 20, 0x2471A3, "threads sum:");
	mlx_string_put(mlx, win, x2, y, 0xAED6F1, "left/right (mouse scroll)");
	mlx_string_put(mlx, win, x, y += 20, 0x2471A3, "fract zoom:");
	mlx_string_put(mlx, win, x2, y, 0xAED6F1, "+/- or up/down (mouse scroll)");
}

void		draw_menu_end(t_windw *wind)
{
	int		x;
	int		x2;
	int		y;
	void	*mlx;
	void	*win;

	mlx = wind->mlx_ptr;
	win = wind->win_ptr;
	x = 40;
	x2 = 240;
	y = 60;
	mlx_string_put(mlx, win, x, y += 60, 0x2471A3, "theads:");
	if ((wind->evnt.threads_num = ft_itoa((int)wind->threads_sum)))
		mlx_string_put(mlx, win, x2, y, 0x00FF00, wind->evnt.threads_num);
	else
		mlx_string_put(mlx, win, 240, y, 0x00FF00, "can't calculate");
	ft_strdel(&wind->evnt.threads_num);
	mlx_string_put(mlx, win, x, y += 20, 0x2471A3, "color by iter:");
	if (wind->color_iter == 0)
		mlx_string_put(mlx, win, x2, y, 0x00FF00, "ON");
	else
		mlx_string_put(mlx, win, x2, y, 0x00FF00, "OFF");
	draw_menu_helper2(wind);
}
