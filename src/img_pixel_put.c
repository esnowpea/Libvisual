/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 16:24:04 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/17 16:25:12 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"

void		img_pixel_put(t_img *img, t_point p)
{
	if (p.x >= 0 && p.x < WIN_WIDTH && p.y >= 0 && p.y < WIN_HEIGHT)
	{
		img->data[p.x * 4 + 4 * WIN_WIDTH * p.y] = p.color.blue;
		img->data[p.x * 4 + 4 * WIN_WIDTH * p.y + 1] = p.color.green;
		img->data[p.x * 4 + 4 * WIN_WIDTH * p.y + 2] = p.color.red;
		img->data[p.x * 4 + 4 * WIN_WIDTH * p.y + 3] = p.color.alpha;
	}
}
