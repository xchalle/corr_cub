/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:49 by xchalle           #+#    #+#             */
/*   Updated: 2021/04/20 14:52:29 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		end(t_h *h)
{
	mlx_loop_end(h->img.mlx);
	return (1);
}

void	ft_move2(t_h *h)
{
	if ((h->p.rotangle < (3 * M_PI / 4) && h->p.rotangle > (M_PI / 4)) ||
			(h->p.rotangle > (5 * M_PI / 4) && h->p.rotangle < (7 * M_PI / 4)))
	{
		if (ft_hitwall(h, h->p.posx, h->p.newposy) == 0)
			h->p.posy = h->p.newposy;
		else
			h->p.newposy = h->p.posy;
		if (ft_hitwall(h, h->p.newposx, h->p.posy) == 0)
			h->p.posx = h->p.newposx;
		else
			h->p.newposx = h->p.posx;
	}
	if ((h->p.rotangle > (3 * M_PI / 4) && h->p.rotangle < (5 * M_PI / 4)) ||
			(h->p.rotangle > (7 * M_PI / 4) || h->p.rotangle < (M_PI / 4)))
	{
		if (ft_hitwall(h, h->p.newposx, h->p.posy) == 0)
			h->p.posx = h->p.newposx;
		else
			h->p.newposx = h->p.posx;
		if (ft_hitwall(h, h->p.posx, h->p.newposy) == 0)
			h->p.posy = h->p.newposy;
		else
			h->p.newposy = h->p.posy;
	}
}

void	ft_move(t_h *h, long *ceiling, long *floor)
{
	*ceiling = ((h->s.ceiling[0] & 0xff) << 16) +
		((h->s.ceiling[1] & 0xff) << 8) + ((h->s.ceiling[2] & 0xff));
	*floor = ((h->s.floor[0] & 0xff) << 16) +
		((h->s.floor[1] & 0xff) << 8) + ((h->s.floor[2] & 0xff));
	draw_rect(h, 0, 0, *ceiling);
	draw_rect(h, 0, h->s.reso[1] / h->p.crouch, *floor);
	h->p.rotangle += h->p.rotadir * h->p.rotaspeed;
	h->p.newposy -= sin(h->p.rotangle) * h->p.walkdir * h->p.movespeed +
		sin(h->p.rotangle + M_PI / 2) * h->p.walkdirx * h->p.movespeed;
	h->p.newposx -= cos(h->p.rotangle) * h->p.walkdir * h->p.movespeed +
		cos(h->p.rotangle + M_PI / 2) * h->p.walkdirx * h->p.movespeed;
	h->p.rotangle = fmod(h->p.rotangle, (2 * M_PI));
	ft_move2(h);
}

void	rien2(t_h *h, int i)
{
	while (i < h->s.reso[0])
	{
		h->p.fov = fmod(h->p.fov, (2 * M_PI));
		if (h->p.fov < 0)
			h->p.fov += (2 * M_PI);
		draw_line(h, i, 0x00B4BACC);
		h->p.fov += FOV * (M_PI / 180) / h->s.reso[0];
		i++;
	}
}

int		rien(t_h *h)
{
	int		i;
	long	ceiling;
	long	floor;

	i = 0;
	reset_sprite(h);
	h->p.rotangle = fmod(h->p.rotangle, (2 * M_PI));
	if (h->p.rotangle < 0)
		h->p.rotangle += (2 * M_PI);
	ft_move(h, &ceiling, &floor);
	h->p.fov = h->p.rotangle - (FOV / 2) * (M_PI / 180);
	rien2(h, i);
	i = 0;
	h->p.fov = h->p.rotangle - (FOV / 2) * (M_PI / 180);
	h->fovi = (FOV / 2);
	if (h->save == 0)
		mlx_put_image_to_window(h->img.mlx, h->img.mlx_win, h->img.img, 0, 0);
	else
	{
		write_bmp(h);
		ft_destroy_img_end(h);
		ft_free_struct(h);
		exit(0);
	}
	return (0);
}
