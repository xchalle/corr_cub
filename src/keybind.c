/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:05:19 by xchalle           #+#    #+#             */
/*   Updated: 2021/05/25 10:11:30 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	press(int keycode, t_h *h)
{
	if (keycode == ESC)
		mlx_loop_end(h->img.mlx);
	if (keycode == Z)
		h->p.walkdir = 1;
	if (keycode == S)
		h->p.walkdir = -1;
	if (keycode == D)
		h->p.walkdirx = 1;
	if (keycode == Q)
		h->p.walkdirx = -1;
	if (keycode == RIGHT_ARROW)
		h->p.rotadir = 1;
	if (keycode == LEFT_ARROW)
		h->p.rotadir = -1;
	else
		return (1);
	return (0);
}

int	release(int keycode, t_h *h)
{
	if (keycode == Z)
		h->p.walkdir = 0;
	if (keycode == S)
		h->p.walkdir = 0;
	if (keycode == D)
		h->p.walkdirx = 0;
	if (keycode == Q)
		h->p.walkdirx = 0;
	if (keycode == RIGHT_ARROW)
		h->p.rotadir = 0;
	if (keycode == LEFT_ARROW)
		h->p.rotadir = 0;
	if (keycode == CROUCH)
		h->p.crouch = 2;
	else
		return (1);
	return (0);
}
