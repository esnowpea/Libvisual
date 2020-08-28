/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:24:23 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/18 15:26:29 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"

t_point			set_point(int x, int y, t_color color)
{
	t_point		p;

	p.x = x;
	p.y = y;
	p.color = color;
	return (p);
}

t_point_d		set_point_d(double x, double y, t_color color)
{
	t_point_d		p;

	p.x = x;
	p.y = y;
	p.color = color;
	return (p);
}
