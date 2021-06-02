/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_ver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:06:07 by xchalle           #+#    #+#             */
/*   Updated: 2021/05/25 10:12:42 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	my_mlx_pixel_find(t_d *d, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0 || x > d->x_img || y > d->y_img)
	{
		return (0);
	}
	dst = d->addr + (y * d->line_length
			+ x * (d->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	calc_hit_sprite_v(t_h *h)
{
	if (h->c.den != 0)
	{
		h->c.t = ((h->c.lx1 - h->p.posx) * (h->p.posy - h->r.y)
				- (h->c.ly1 - h->p.posy)
				* (h->p.posx - h->r.x)) / h->c.den;
		h->c.u = -((h->c.lx1 - h->c.lx2) * (h->c.ly1 - h->p.posy)
				- (h->c.ly1 - h->c.ly2)
				* (h->c.lx1 - h->p.posx)) / h->c.den;
		if (h->c.t > 0 && h->c.t < 1 && h->c.u > 0)
		{
			h->c.ptx = h->p.posx + h->c.u * (h->r.x - h->p.posx);
			h->c.pty = h->p.posy + h->c.u * (h->r.y - h->p.posy);
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

void	hit_sprite_v(t_h *h)
{
	h->c.centerx = (int)h->r.x / (int)CUB
		* (int)CUB + CUB / 2;
	h->c.centery = (int)h->r.y / (int)CUB
		* (int)CUB + CUB / 2;
	if (h->r.side_x == 0)
		h->r.x++;
	h->c.ly1 = h->c.centery + sin(h->p.rotangle + M_PI / 2)
		* (CUB / 2);
	h->c.lx1 = h->c.centerx + cos(h->p.rotangle + M_PI / 2)
		* (CUB / 2);
	h->c.ly2 = h->c.centery - sin(h->p.rotangle + M_PI / 2)
		* (CUB / 2);
	h->c.lx2 = h->c.centerx - cos(h->p.rotangle + M_PI / 2)
		* (CUB / 2);
	h->c.den = (h->c.lx1 - h->c.lx2) * (h->p.posy - h->r.y)
		- (h->c.ly1 - h->c.ly2) * (h->p.posx - h->r.x);
	if (h->i < h->sprt)
		calc_hit_sprite_v(h);
}

double	ft_raycasting_ver2(t_h *h, double posx, double posy)
{
	while (h->r.x >= 0 && h->r.x < (CUB * h->longe)
		&& h->r.y >= 0 && h->r.y < (CUB * h->longe))
	{
		if (ft_hitwall(h, h->r.x, h->r.y) == 2)
		{
			hit_sprite_v(h);
			if (h->r.side_x == 0)
				h->r.x--;
		}
		if (ft_hitwall(h, h->r.x, h->r.y) == 1)
		{
			if (h->r.side_x == 0)
				h->r.x++;
			h->p.hitx_vert = h->r.x;
			h->p.hity_vert = h->r.y;
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

double	ft_raycasting_ver(t_h *h, double posx, double posy)
{
	h->r.side_y = 1;
	h->r.side_x = 0;
	while (h->p.fov < 0)
		h->p.fov += (2 * M_PI);
	if (h->p.fov < 1.5 * (M_PI) && h->p.fov > (M_PI / 2))
		h->r.side_x = CUB;
	h->r.x = floor(posx / CUB) * CUB;
	h->r.x += h->r.side_x;
	if (h->p.fov < (M_PI) && h->p.fov > 0)
		h->r.side_y = -1;
	h->r.y = posy + (h->r.x - posx) * tan(h->p.fov);
	if (h->r.side_x != 0)
		h->r.xstep = CUB;
	else
		h->r.xstep = -CUB;
	h->r.ystep = CUB * tan(h->p.fov);
	if (h->r.ystep > 0 && h->r.side_y == -1)
		h->r.ystep *= -1;
	if (h->r.ystep < 0 && h->r.side_y == 1)
		h->r.ystep *= -1;
	if (h->r.side_x == 0)
		h->r.x--;
	return (ft_raycasting_ver2(h, posx, posy));
}
