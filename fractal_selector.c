/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 03:11:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/11/20 16:39:05 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	julia(t_windw *wind, t_comp *comp)
{
	comp->tmp_i = comp->real_num * comp->real_num - comp->imagin_num *
			comp->imagin_num + wind->mouse_y;
	comp->tmp_r = 2 * comp->real_num * comp->imagin_num + wind->mouse_x;
}

void	mandelbrot(t_comp *comp)
{
	comp->tmp_r = comp->real_num * comp->real_num
				- comp->imagin_num * comp->imagin_num + comp->correctiv_x;
	comp->tmp_i = 2 * comp->real_num * comp->imagin_num + comp->correctiv_y;
}

void	tricorn(t_comp *comp)
{
	comp->tmp_i = comp->real_num * comp->imagin_num * -2.0 +
			comp->correctiv_y;
	comp->tmp_r = comp->real_num * comp->real_num -
			comp->imagin_num * comp->imagin_num + comp->correctiv_x;
}

void	burning_ship(t_comp *comp)
{
	comp->tmp_i = fabs(comp->real_num * comp->imagin_num) * 2.0 +
			comp->correctiv_y;
	comp->tmp_r = comp->real_num * comp->real_num - comp->imagin_num *
			comp->imagin_num + comp->correctiv_x;
}

void	perpen_burning_ship(t_comp *comp)
{
	comp->tmp_i = comp->real_num * fabs(comp->imagin_num) * 2.0 +
			comp->correctiv_y;
	comp->tmp_r = comp->real_num * comp->real_num - comp->imagin_num *
			comp->imagin_num + comp->correctiv_x;
}
