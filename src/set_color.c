/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:48:21 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/28 17:15:25 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"

t_color			set_color(t_color_d c)
{
	t_color	color;

	color.alpha = (unsigned char)c.alpha;
	color.red = (unsigned char)c.red;
	color.green = (unsigned char)c.green;
	color.blue = (unsigned char)c.blue;
	return (color);
}

t_color_d		set_color_d(t_color c)
{
	t_color_d	color;

	color.alpha = (double)c.alpha;
	color.red = (double)c.red;
	color.green = (double)c.green;
	color.blue = (double)c.blue;
	return (color);
}
