/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_line_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 16:28:50 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/20 15:52:53 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"

static t_color_d	find_color(t_point p1, t_point p2, t_point p3)
{
	double		s;
	double		ds;
	t_color_d	color;

	ds = sqrt(pow((double)(p3.x - p1.x), 2) + pow((double)(p3.y - p1.y), 2));
	s = sqrt(pow((double)(p2.x - p1.x), 2) + pow((double)(p2.y - p1.y), 2));
	color.alpha = p1.color.alpha +
			(double)(p2.color.alpha - p1.color.alpha) / s * ds;
	color.red = p1.color.red +
			(double)(p2.color.red - p1.color.red) / s * ds;
	color.green = p1.color.green +
			(double)(p2.color.green - p1.color.green) / s * ds;
	color.blue = p1.color.blue +
			(double)(p2.color.blue - p1.color.blue) / s * ds;
	return (color);
}

void				img_line_put(t_img *img, t_point p1, t_point p2)
{
	t_point_d	p;
	t_color_d	color;
	double		sign_x;
	double		sign_y;

	p = set_point_d((double)p1.x, (double)p1.y, p1.color);
	sign_x = p1.x < p2.x ? 1 : -1;
	sign_y = p1.y < p2.y ? 1 : -1;
	while ((int)round(p.x) != p2.x || (int)round(p.y) != p2.y)
	{
		color = find_color(p1, p2, set_point((int)p.x, (int)p.y, p1.color));
		img_pixel_put(img, set_point((int)p.x, (int)p.y, set_color(color)));
		if ((double)abs(p2.x - p1.x) > (double)abs(p2.y - p1.y))
			p = set_point_d(p.x + sign_x,
			p.y + (double)abs(p2.y - p1.y) /
			(double)abs(p2.x - p1.x) * sign_y, p1.color);
		else
			p = set_point_d(p.x + (double)abs(p2.x - p1.x) /
			(double)abs(p2.y - p1.y) * sign_x,
			p.y + sign_y, p1.color);
	}
	img_pixel_put(img, p2);
}
