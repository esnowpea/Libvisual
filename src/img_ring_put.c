/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_circle_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:58:52 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/24 12:19:00 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"

void		img_ring_put(t_img *img, t_point p1, int r)
{
	double		fi;
	t_point		p2;
	t_point		tmp;

	fi = 0;
	tmp = set_point((int)(r * cos(fi)) + p1.x, (int)(r * sin(fi)) + p1.y,
	p1.color);
	while (fi < 2 * M_PI)
	{
		p2 = set_point((int)(r * cos(fi)) + p1.x, (int)(r * sin(fi)) + p1.y,
		p1.color);
		img_line_put(img, tmp, p2);
		tmp = p2;
		fi += 1 / (double)r;
	}
}
