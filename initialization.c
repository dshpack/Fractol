/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 02:18:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/11/20 16:21:36 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_fract_limits(t_windw *wind)
{
	wind->fract.manb_re[0] = -2;
	wind->fract.manb_im[0] = -1.2;
	wind->fract.manb_im[1] = 1.2;
	wind->fract.manb_re[1] = wind->width
		* ((wind->fract.manb_im[1] - wind->fract.manb_im[0]) / wind->height)
		+ wind->fract.manb_re[0];
	wind->fract.remin = wind->fract.manb_re[0];
	wind->fract.remax = wind->fract.manb_re[1];
	wind->fract.immin = wind->fract.manb_im[0];
	wind->fract.immax = wind->fract.manb_im[1];
}

t_windw		*init_window(void)
{
	t_windw		*wind;

	wind = (t_windw *)malloc(sizeof(t_windw));
	ft_bzero(wind, sizeof(t_windw));
	wind->width = 1200;
	wind->height = 800;
	wind->mlx_ptr = mlx_init();
	wind->win_ptr = mlx_new_window(wind->mlx_ptr, wind->width, wind->height,
									"Fractol project by dshpack");
	wind->img_ptr =
			mlx_new_image(wind->mlx_ptr, wind->width, wind->height);
	wind->address = (int *)mlx_get_data_addr(wind->img_ptr, &wind->bpp,
												&wind->s_line, &wind->endian);
	wind->evnt.iter = 70;
	wind->selector = 1;
	set_fract_limits(wind);
	wind->evnt.zoom_sum = 0;
	wind->effect = 1;
	wind->c = 1;
	wind->threads_sum = 4;
	wind->color_iter = 0;
	return (wind);
}
