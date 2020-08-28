/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 16:50:32 by esnowpea          #+#    #+#             */
/*   Updated: 2020/08/18 15:27:46 by esnowpea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvisual.h"
#include "error_message.h"

void				terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

static t_img		*init_image(void *mlx)
{
	t_img		*image;

	if (!(image = (t_img *)ft_memalloc(sizeof(t_img))))
		terminate(ERR_IMAGE_INIT);
	if (!(image->img_ptr = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT)))
		terminate(ERR_IMAGE_INIT);
	image->data = mlx_get_data_addr(
			image->img_ptr,
			&(image->bpp),
			&(image->size_l),
			&(image->endian));
	return (image);
}

void				set_defaults(t_win *win)
{
	win->mouse_press = 0;
	win->space_press = 0;
	win->ctrl_press = 0;
}

t_win				*init_visual(char *name)
{
	t_win		*win;

	if (!(win = (t_win *)ft_memalloc(sizeof(t_win))))
		terminate(ERR_MALLOC_INIT);
	if (!(win->mlx = mlx_init()))
		terminate(ERR_MLX_INIT);
	if (!(win->win = mlx_new_window(win->mlx, WIN_WIDTH, WIN_HEIGHT, name)))
		terminate(ERR_WINDOW_INIT);
	win->img = init_image(win->mlx);
	return (win);
}
