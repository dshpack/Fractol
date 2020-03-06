/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 02:21:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/11/20 16:01:49 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_px(t_windw *wind, int x, int y, int c)
{
	int		color;

	if (x >= 0 && y >= 0 && x < wind->width && y < wind->height)
	{
		color = (wind->effect > 0) ? c : 0xca000000 | c;
		wind->address[y * wind->width + x] = color;
	}
}

int		get_col(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / (double)max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r + g + b);
}
