/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 21:12:00 by dshpack           #+#    #+#             */
/*   Updated: 2018/11/21 18:17:01 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <pthread.h>
# define MAX_INT 2147483647

enum				e_keys
{
	MANDELBROT_SELECT = 18,
	SHIP_SELECT = 22,
	PERPEN_SHIP_SELECT = 26,
	TRICORN_SELECT = 21,
	CELTIC_SELECT = 19,
	PERPEN_MAN_SELECT = 23,
	HEART_MAN_SELECT = 20,
	JULIA_SELECT = 28,
	CUBIC_SELECT = 25,
	MANDELBAR_5TH = 29,
	COLOR_BY_ITER = 8,
	EF_NORMAL = 83,
	EF_MISTIC = 88,
	EF_STARS = 84,
	EF_STAINED_GLASS = 86,
	EF_BLACK = 87,
	EF_FAT_STARS = 85,
	SCALE_PLUS = 24,
	SCALE_MINUS = 27,
	COLOR_PLUS = 116,
	COLOR_MINUS = 121,
	ITER_PLUS = 69,
	ITER_MINUS = 78,
	JULIA_LOCK = 49,
	MOVE_X_TO_LEFT = 123,
	MOVE_X_TO_RIGHT = 124,
	MOVE_Y_TO_TOP = 126,
	MOVE_Y_TO_BOTTOM = 125,
	BACK_TO_START = 51,
	MENU_DRAW = 46,
	ESCAPE = 53
};

typedef struct		s_events
{
	double			move_x;
	double			move_y;
	int				mouse_lock;
	int				julia_lock;
	double			scale;
	int				iter;
	int				zoom_sum;
	int				menu_draw;
	char			*iter_num;
	char			*threads_num;
}					t_events;

typedef struct		s_fracts
{
	double			remin;
	double			remax;
	double			immin;
	double			immax;
	double			x_center;
	double			y_center;
	double			manb_re[2];
	double			manb_im[2];
}					t_fract;

typedef struct		s_window
{
	double			mrel;
	double			mimg;
	int				width;
	int				height;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*address;
	int				bpp;
	int				s_line;
	int				endian;
	t_events		evnt;
	t_fract			fract;
	int				effect;
	int				selector;
	int				c;
	int				color_iter;
	size_t			threads_sum;
	double			mouse_x;
	double			mouse_y;
}					t_windw;

typedef struct		s_complex
{
	double			correctiv_x;
	double			correctiv_y;
	double			tmp_r;
	double			tmp_i;
	double			real_num;
	double			imagin_num;
	double			cofx;
	double			cofy;
	int				thread_id;
}					t_comp;

typedef struct		s_threads
{
	size_t			id;
	t_windw			*wind;
}					t_thread;

void				print_error_and_close(int flag);
void				put_message(int message);
t_windw				*init_window();
void				set_fract_limits(t_windw *wind);
void				julia(t_windw *wind, t_comp *comp);
void				mandelbrot(t_comp *comp);
void				burning_ship(t_comp *comp);
void				perpen_burning_ship(t_comp *comp);
void				tricorn(t_comp *comp);
void				celtic_mandelbrot(t_comp *comp);
void				perpen_mandelbrot(t_comp *comp);
void				heart_mandelbrot(t_comp *comp);
void				cubic_mandelbrot(t_comp *comp);
void				mandelbar_5th(t_comp *comp);
void				draw_menu_rectangle(t_windw *wind);
void				draw_menu_info(t_windw *windw);
void				draw_menu_end(t_windw *wind);
void				set_px(t_windw *wind, int x, int y, int c);
int					mouse_pos(int x, int y, t_windw *wind);
void				ptr_freashing(t_windw *wind);
void				del_map_and_exit(t_windw *wind, int error_flag);
void				drawing(t_windw *wind, size_t threads_sum);
void				change_zoom(int key, double x, double y, t_windw *wind);
void				fract_set(char *str, int *id);
int					validation(char *str);
void				rotating_and_scaling(int key, t_windw *wind);
void				menu_wmk_pushes(int key, t_windw *w);
void				to_start(int key, t_windw *wind);
int					get_col(int iter, int max_iter);

#endif
