/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:28 by xchalle           #+#    #+#             */
/*   Updated: 2021/04/21 13:31:50 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	sort_sprite(t_h *h)
{
	int		i;
	int		j;
	double	tmp;

	i = 0;
	while (i < h->sprt)
	{
		j = i + 1;
		while (j < h->sprt)
		{
			if (h->u[i].d < h->u[j].d)
			{
				tmp = h->u[i].d;
				h->u[i].d = h->u[j].d;
				h->u[j].d = tmp;
				tmp = h->u[i].p;
				h->u[i].p = h->u[j].p;
				h->u[j].p = tmp;
			}
			j++;
		}
		i++;
	}
}

void	draw_wall(t_h *h, int i, int j, long double di)
{
	if (h->p.bool_vert == 1 && (h->p.fov > (M_PI / 2)
				&& h->p.fov < (1.5 * M_PI)))
		my_mlx_pixel_put(h, i, di, my_mlx_pixel_find(&h->img3,
					(h->img3.x_img * (h->pourcent / CUB)),
					(h->img3.y_img * (j / h->dist_max))));
	if (h->p.bool_vert == 1 && (h->p.fov <= (M_PI / 2) ||
				h->p.fov >= (1.5 * M_PI)))
		my_mlx_pixel_put(h, i, di, my_mlx_pixel_find(&h->img2,
					(h->img2.x_img * (h->pourcent / CUB)),
					(h->img2.y_img * (j / h->dist_max))));
	if (h->p.bool_vert == 0 && (h->p.fov > (M_PI) ||
				h->p.fov < 0))
		my_mlx_pixel_put(h, i, di, my_mlx_pixel_find(&h->img4,
					(h->img4.x_img * (h->pourcent / CUB)),
					(h->img4.y_img * (j / h->dist_max))));
	if (h->p.bool_vert == 0 && (h->p.fov >= 0
				&& h->p.fov <= M_PI))
		my_mlx_pixel_put(h, i, di, my_mlx_pixel_find(&h->img5,
					(h->img5.x_img * (h->pourcent / CUB)),
					(h->img5.y_img * (j / h->dist_max))));
}

void	draw_sprite2(t_h *h, int i, int u, int k)
{
	int	di;

	h->u[u].d = h->u[u].d * cos(h->p.rotangle - h->p.fov);
	if (h->u[u].d != 0)
		h->u[u].d = -(8 * CUB / h->u[u].d)
			* ((h->s.reso[0] / 2) / tan(FOV / 2));
	di = ((h->s.reso[1] - h->u[u].d)) / h->p.crouch;
	while (di < 0)
	{
		k -= (int)di - 1;
		di -= (int)di - 1;
	}
	while (k < h->u[u].d)
	{
		if (di > h->s.reso[1])
			break ;
		my_mlx_pixel_put(h, i, di, my_mlx_pixel_find(&h->img6,
			(h->img6.x_img * h->u[u].p / CUB),
			(h->img6.y_img * (k / h->u[u].d * 1))));
		k++;
		di++;
	}
}

void	draw_sprite(t_h *h, int di, int i, double wall_size)
{
	int	k;
	int	u;

	(void)di;
	u = 0;
	while (u < h->i)
	{
		k = 0;
		if (h->u[u].d < wall_size)
			draw_sprite2(h, i, u, k);
		u++;
	}
}

void	draw_line2(t_h *h, int i, double dist_max)
{
	long double	di;
	double		j;
	double		wall_size;

	wall_size = dist_max;
	dist_max = dist_max * cos(h->p.rotangle - h->p.fov);
	if (dist_max != 0)
		dist_max = -(8 * CUB / dist_max) *
			((h->s.reso[0] / 2) / tan(FOV / 2));
	di = ((h->s.reso[1] - dist_max)) / h->p.crouch;
	h->dist_max = dist_max;
	j = 0;
	trim(&di, &j);
	while (j < dist_max)
	{
		if (di > h->s.reso[1])
			break ;
		draw_wall(h, i, j, di);
		j += 1;
		di += 1;
	}
	sort_sprite(h);
	draw_sprite(h, di, i, wall_size);
}
