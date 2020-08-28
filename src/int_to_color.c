/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:38:04 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/17 17:38:04 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"

t_color		int_to_color(int int_color)
{
	t_color		color;

	color.alpha = (int_color >> 24) & 0xff;
	color.red = (int_color >> 16) & 0xff;
	color.green = (int_color >> 8) & 0xff;
	color.blue = (int_color >> 0) & 0xff;
	return (color);
}

int			color_to_int(t_color color)
{
	return (((int)color.alpha << 24) + ((int)color.red << 16) +
	((int)color.green << 8) + (int)color.blue);
}
