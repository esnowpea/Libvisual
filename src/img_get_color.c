/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_get_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:56:09 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/28 14:56:09 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"

t_color		img_get_color(t_img *img, int x, int y)
{
	t_color		color;

	color.alpha = 0;
	color.green = 0;
	color.red = 0;
	color.blue = 0;
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		color.blue = img->data[x * 4 + 4 * WIN_WIDTH * y];
		color.green = img->data[x * 4 + 4 * WIN_WIDTH * y + 1];
		color.red = img->data[x * 4 + 4 * WIN_WIDTH * y + 2];
		color.alpha = img->data[x * 4 + 4 * WIN_WIDTH * y + 3];
	}
	return (color);
}
