/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_hor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:05:53 by xchalle           #+#    #+#             */
/*   Updated: 2021/04/20 19:12:52 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_h *h, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= h->s.reso[0] || y >= h->s.reso[1])
		return ;
	if (color < 0)
		return ;
	dst = h->img.addr + (y * h->img.line_length +
			x * (h->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	calc_hit_sprite_h(t_h *h)
{
	if (h->c.den != 0)
	{
		h->c.t = ((h->c.lx1 - h->p.posx) * (h->p.posy - h->r.y) -
				(h->c.ly1 - h->p.posy) *
				(h->p.posx - h->r.x)) / h->c.den;
		h->c.u = -((h->c.lx1 - h->c.lx2) * (h->c.ly1 - h->p.posy) -
				(h->c.ly1 - h->c.ly2) *
				(h->c.lx1 - h->p.posx)) / h->c.den;
		if (h->c.t > 0 && h->c.t < 1 && h->c.u > 0)
		{
			h->c.ptx = h->c.lx1 + (h->c.t * (h->c.lx2 - h->c.lx1));
			h->c.pty = h->c.ly1 + (h->c.t * (h->c.ly2 - h->c.ly1));
			h->u[h->i].d = hypot(h->c.centerx - h->p.posx,
					h->c.centery - h->p.posy);
			h->u[h->i].p = hypot(h->c.lx1 - h->c.ptx,
					h->c.ly1 - h->c.pty);
			h->i++;
		}
	}
	else
	{
		h->u[h->i].d = 0;
		return ;
	}
}

void	hit_sprite_h(t_h *h)
{
	h->c.centerx = (int)h->r.x / (int)CUB
		* (int)CUB + CUB / 2;
	h->c.centery = (int)h->r.y / (int)CUB
		* (int)CUB + CUB / 2;
	if (h->r.side_y == 0)
		h->r.y++;
	h->c.ly1 = h->c.centery + sin(h->p.rotangle + M_PI / 2)
		* (CUB / 2);
	h->c.lx1 = h->c.centerx + cos(h->p.rotangle + M_PI / 2)
		* (CUB / 2);
	h->c.ly2 = h->c.centery - sin(h->p.rotangle + M_PI / 2)
		* (CUB / 2);
	h->c.lx2 = h->c.centerx - cos(h->p.rotangle + M_PI / 2)
		* (CUB / 2);
	h->c.den = (h->c.lx1 - h->c.lx2) * (h->p.posy - h->r.y) -
		(h->c.ly1 - h->c.ly2) * (h->p.posx - h->r.x);
	if (h->i < h->sprt)
		calc_hit_sprite_h(h);
}

double	ft_raycasting_hor2(t_h *h, double posx, double posy)
{
	while (h->r.x >= 0 && h->r.x < (CUB * (h->longe + 1))
			&& h->r.y >= 0 && h->r.y < (CUB * (h->longe + 1)))
	{
		if (ft_hitwall(h, h->r.x, h->r.y) == 2)
		{
			hit_sprite_h(h);
			if (h->r.side_y == 0)
				h->r.y--;
		}
		if (ft_hitwall(h, h->r.x, h->r.y) == 1)
		{
			if (h->r.side_y == 0)
				h->r.y++;
			h->p.hitx_horz = h->r.x;
			h->p.hity_horz = h->r.y;
			return (hypot(h->r.x - posx, h->r.y - posy));
		}
		else
		{
			h->r.x += h->r.xstep;
			h->r.y += h->r.ystep;
		}
	}
	return (CUB * (h->longe + 1) + 1000000);
}

double	ft_raycasting_hor(t_h *h, double posx, double posy)
{
	h->r.side_x = -1;
	h->r.side_y = CUB;
	while (h->p.fov <= 0)
		h->p.fov += (2 * M_PI);
	if (h->p.fov < (M_PI) && h->p.fov > 0)
		h->r.side_y = 0;
	h->r.y = floor(posy / CUB) * CUB;
	h->r.y += h->r.side_y;
	if (h->p.fov < 1.5 * (M_PI) && h->p.fov > (M_PI / 2))
		h->r.side_x = 1;
	h->r.x = posx + (h->r.y - posy) / tan(h->p.fov);
	if (h->r.side_y != 0)
		h->r.ystep = CUB;
	else
		h->r.ystep = -CUB;
	h->r.xstep = CUB / tan(h->p.fov);
	if (h->r.xstep > 0 && h->r.side_x == -1)
		h->r.xstep *= -1;
	if (h->r.xstep < 0 && h->r.side_x == 1)
		h->r.xstep *= -1;
	if (h->r.side_y == 0)
		h->r.y--;
	return (ft_raycasting_hor2(h, posx, posy));
}
