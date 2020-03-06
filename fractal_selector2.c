/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_selector2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:32:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/11/20 16:38:50 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	celtic_mandelbrot(t_comp *comp)
{
	comp->tmp_i = comp->real_num * comp->imagin_num * 2.0 + comp->correctiv_y;
	comp->tmp_r = fabs(comp->real_num * comp->real_num -
					comp->imagin_num * comp->imagin_num) + comp->correctiv_x;
}

void	heart_mandelbrot(t_comp *comp)
{
	comp->tmp_i = fabs(comp->real_num) *
					comp->imagin_num * 2.0 + comp->correctiv_y;
	comp->tmp_r = comp->real_num * comp->real_num -
					comp->imagin_num * comp->imagin_num + comp->correctiv_x;
}

void	perpen_mandelbrot(t_comp *comp)
{
	comp->tmp_i = fabs(comp->real_num) * comp->imagin_num * -2.0 +
					comp->correctiv_y;
	comp->tmp_r = comp->real_num * comp->real_num - comp->imagin_num *
					comp->imagin_num + comp->correctiv_x;
}

void	cubic_mandelbrot(t_comp *comp)
{
	comp->tmp_i = ((comp->real_num * comp->real_num * 3.0) -
					(comp->imagin_num * comp->imagin_num)) *
					comp->tmp_i + comp->correctiv_y;
	comp->tmp_r = ((comp->real_num * comp->real_num -
					(comp->imagin_num * comp->imagin_num * 3.0))) *
					comp->tmp_r + comp->correctiv_x;
}

void	mandelbar_5th(t_comp *comp)
{
	comp->tmp_i = ((comp->real_num * comp->real_num * 3.0) -
					(comp->imagin_num * comp->imagin_num)) *
					comp->tmp_i + comp->correctiv_y;
	comp->tmp_r = ((comp->real_num * comp->real_num -
					(comp->imagin_num * comp->imagin_num * 3.0)))
					* comp->tmp_r + comp->correctiv_x;
}
