/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 02:25:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/11/20 16:30:14 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_set(char *str, int *id)
{
	if (!ft_strcmp(str, "Mandelbrot") || !ft_strcmp(str, "M"))
		*id = 1;
	else if (!ft_strcmp(str, "Celtic") || !ft_strcmp(str, "C"))
		*id = 2;
	else if (!ft_strcmp(str, "Heart") || !ft_strcmp(str, "H"))
		*id = 3;
	else if (!ft_strcmp(str, "Tricorn") || !ft_strcmp(str, "T"))
		*id = 4;
	else if (!ft_strcmp(str, "Perpen_Mandelbrot") || !ft_strcmp(str, "PM"))
		*id = 5;
	else if (!ft_strcmp(str, "Ship") || !ft_strcmp(str, "S"))
		*id = 6;
	else if (!ft_strcmp(str, "Perpen_Ship") || !ft_strcmp(str, "PS"))
		*id = 7;
	else if (!ft_strcmp(str, "Julia") || !ft_strcmp(str, "J"))
		*id = 8;
	else if (!ft_strcmp(str, "Cubic_Mandelbrot") || !ft_strcmp(str, "CM"))
		*id = 9;
	else if (!ft_strcmp(str, "Mandelbar_five") || !ft_strcmp(str, "M5"))
		*id = 10;
}

int		validation(char *str)
{
	if (!ft_strcmp(str, "Mandelbrot") || !ft_strcmp(str, "M") ||
		!ft_strcmp(str, "Celtic") || !ft_strcmp(str, "C") ||
		!ft_strcmp(str, "Heart") || !ft_strcmp(str, "H") ||
		!ft_strcmp(str, "Tricorn") || !ft_strcmp(str, "T") ||
		!ft_strcmp(str, "Perpen_Mandelbrot") || !ft_strcmp(str, "PM") ||
		!ft_strcmp(str, "Ship") || !ft_strcmp(str, "S") ||
		!ft_strcmp(str, "Perpen_Ship") || !ft_strcmp(str, "PS") ||
		!ft_strcmp(str, "Julia") || !ft_strcmp(str, "J") ||
		!ft_strcmp(str, "Cubic_Mandelbrot") || !ft_strcmp(str, "CM") ||
		!ft_strcmp(str, "Mandelbar_five") || !ft_strcmp(str, "M5"))
	{
		return (0);
	}
	return (1);
}
