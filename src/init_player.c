/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:05:10 by xchalle           #+#    #+#             */
/*   Updated: 2021/04/16 12:48:25 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_h3(t_h *h)
{
	if (h->s.reso[1] + h->s.reso[0] > 400)
	{
		h->p.rotaspeed = 0.5 * (M_PI / 180);
		h->p.movespeed = 0.10;
	}
	if (h->s.reso[1] + h->s.reso[0] > 1000)
	{
		h->p.rotaspeed = 1 * (M_PI / 180);
		h->p.movespeed = 2;
	}
	if (h->s.reso[1] + h->s.reso[0] > 1500)
	{
		h->p.rotaspeed = 1.8 * (M_PI / 180);
		h->p.movespeed = 4.0;
	}
	if (h->s.reso[1] + h->s.reso[0] > 2000)
	{
		h->p.rotaspeed = 2 * (M_PI / 180);
		h->p.movespeed = 6.0;
	}
}

void	ft_init_h2(t_h *h, int screensizex, int screensizey)
{
	if (screensizex < h->s.reso[0])
		h->s.reso[0] = screensizex;
	if (screensizey < h->s.reso[1])
		h->s.reso[1] = screensizey;
	h->p.posx = h->s.posj * CUB + CUB / 2;
	h->p.posy = h->s.posi * CUB + CUB / 2;
	h->p.newposy = h->p.posy;
	h->p.newposx = h->p.posx;
	if (h->s.chara == 'N')
		h->p.rotangle = M_PI / 2;
	if (h->s.chara == 'S')
		h->p.rotangle = 1.5 * M_PI;
	if (h->s.chara == 'E')
		h->p.rotangle = M_PI;
	if (h->s.chara == 'W')
		h->p.rotangle = 2 * M_PI;
	if (h->s.reso[1] + h->s.reso[0] > 0)
	{
		h->p.rotaspeed = 0.1 * (M_PI / 180);
		h->p.movespeed = 0.05;
	}
}

void	ft_init_h(t_h *h, int screensizex, int screensizey)
{
	ft_init_h2(h, screensizex, screensizey);
	ft_init_h3(h);
	if (h->s.reso[1] + h->s.reso[0] > 2700)
	{
		h->p.rotaspeed = 2.5 * (M_PI / 180);
		h->p.movespeed = 7;
	}
	h->p.walkdirx = 0;
	h->p.walkdir = 0;
	h->p.rotadir = 0;
	h->p.crouch = 2;
	h->a = 0;
	reset_sprite(h);
}
