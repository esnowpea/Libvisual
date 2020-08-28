/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_rectangle_put.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:43:10 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/28 17:12:00 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"

void				img_rectangle_put(t_img *img, t_point p1, t_point p2)
{
	int	sign;

	sign = p1.y < p2.y ? 1 : -1;
	while (p1.y != p2.y)
	{
		img_line_put(img, p1, set_point(p2.x, p1.y, p2.color));
		p1.y += sign;
	}
}
