/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitwall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:35 by xchalle           #+#    #+#             */
/*   Updated: 2021/05/25 10:11:07 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	reset_sprite(t_h *h)
{
	int	i;

	i = 0;
	while (i < h->sprt)
		h->u[i++].d = 0;
}

void	draw_line(t_h *h, int i, int color)
{
	double	dist_max;

	(void)color;
	dist_max = ft_raycasting_hor(h, h->p.posx, h->p.posy);
	h->p.bool_vert = 0;
	if (dist_max > ft_raycasting_ver(h, h->p.posx, h->p.posy))
	{
		dist_max = ft_raycasting_ver(h, h->p.posx, h->p.posy);
		h->p.bool_vert = 1;
		pourcent_img_vert(h);
	}
	else
		pourcent_img_horz(h);
	draw_line2(h, i, dist_max);
	h->i = 0;
	reset_sprite(h);
}

int	ft_hitwall(t_h *h, double posx, double posy)
{
	int	x;
	int	y;

	x = floor(posx / CUB);
	y = floor(posy / CUB);
	if (y >= 0 && y < h->s.i && x >= 0 && x < h->s.max)
	{
		if (h->s.array[y][x] == '2')
		{
			h->c.base_x = x;
			h->c.base_y = y;
			return (2);
		}
		if (h->s.array[y][x] == '1')
			return (1);
		if (h->s.array[y][x] == ' ')
			return (1);
	}
	return (0);
}

void	draw_rect2(t_h *h, int x, int y, int color)
{
	int	i;
	int	j;
	int	stockx;

	i = 0;
	j = 0;
	stockx = x;
	if (h->p.crouch == 8)
	{
		while (i < h->s.reso[1])
		{
			j = 0;
			x = stockx;
			while (j < h->s.reso[0])
			{
				my_mlx_pixel_put(h, x, y, color);
				x++;
				j++;
			}
			i++;
			y++;
		}
	}
}

void	draw_rect(t_h *h, int x, int y, int color)
{
	int	i;
	int	j;
	int	stockx;

	i = 0;
	j = 0;
	stockx = x;
	if (h->p.crouch == 2)
	{
		while (i < h->s.reso[1] / 2)
		{
			j = 0;
			x = stockx;
			while (j < h->s.reso[0])
			{
				my_mlx_pixel_put(h, x, y, color);
				x++;
				j++;
			}
			i++;
			y++;
		}
	}
	draw_rect2(h, x, y, color);
}
