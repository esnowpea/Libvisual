/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img_to_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:47:23 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/17 17:47:23 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"

void		print_img_to_win(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->img->img_ptr, 0, 0);
}
