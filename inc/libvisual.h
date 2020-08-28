/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvisual.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 16:22:44 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/28 17:16:17 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVISUAL_H
# define LIBVISUAL_H

# include <math.h>
# include <mlx.h>
# include "libft.h"
# include "error_message.h"
# include "key_define.h"

# define WIN_HEIGHT		1200
# define WIN_WIDTH		1400

typedef struct			s_color_d
{
	double				alpha;
	double				red;
	double				green;
	double				blue;
}						t_color_d;

typedef struct			s_color
{
	unsigned char		alpha;
	unsigned char		red;
	unsigned char		green;
	unsigned char		blue;
}						t_color;

typedef struct			s_point
{
	int					x;
	int					y;
	t_color				color;
}						t_point;

typedef struct			s_point_d
{
	double				x;
	double				y;
	t_color				color;
}						t_point_d;

typedef struct			s_img
{
	void				*img_ptr;
	char				*data;
	int					size_l;
	int					bpp;
	int					endian;
}						t_img;

typedef struct			s_win
{
	int					mouse_press;
	int					ctrl_press;
	int					space_press;
	int					x_mouse;
	int					y_mouse;
	void				*mlx;
	void				*win;
	t_img				*img;
}						t_win;

t_point					set_point(int x, int y, t_color color);
t_point_d				set_point_d(double x, double y, t_color color);
t_color					set_color(t_color_d c);
t_color_d				set_color_d(t_color c);
t_color					img_get_color(t_img *img, int x, int y);
void					img_pixel_put(t_img *img, t_point p);
void					img_line_put(t_img *img, t_point p1, t_point p2);
void					img_triangle_put(t_img *img, t_point p1, t_point p2,
						t_point p3);
void					img_rectangle_put(t_img *img, t_point p1, t_point p2);
void					img_ring_put(t_img *img, t_point p1, int r);
t_win					*init_visual(char *name);
t_color					int_to_color(int int_color);
int						color_to_int(t_color color);
void					print_img_to_win(t_win *win);
void					terminate(char *s);

#endif
