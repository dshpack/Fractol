/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:35:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/11/20 16:21:36 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		print_error_and_close(int flag)
{
	if (flag == 1)
	{
		ft_putstr("Usage: ./fractol \"1-th param\"\n"
		"1-th param: [ Mandelbrot | M | Celtic | C | Heart | H | Tricorn | T | "
		"Perpen_Mandelbrot | PM | Ship | S | Perpen_Ship | PS | Julia | J | "
		"Cubic_Mandelbrot | CM | Mandelbar_five | M5 ]\n\n");
	}
	else if (flag == 2)
	{
		ft_putstr("\n"
		"======================================================\n"
		"=                 Sorry, memory low!                 =\n"
		"======================================================\n");
	}
	exit(0);
}
