/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_before_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 05:08:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/11/21 17:30:43 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		del_map_and_exit(t_windw *wind, int error_flag)
{
	if (wind)
	{
		wind = NULL;
		if (error_flag == 1)
			print_error_and_close(1);
	}
}

void		ptr_freashing(t_windw *wind)
{
	if (wind->img_ptr)
		mlx_destroy_image(wind->mlx_ptr, wind->img_ptr);
	del_map_and_exit(wind, 0);
}
