/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:59 by xchalle           #+#    #+#             */
/*   Updated: 2021/04/14 14:29:21 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_destroy_img(t_h *h)
{
	if (h->img_verif > 2)
		mlx_destroy_image(h->img.mlx, h->img2.img);
	if (h->img_verif > 3)
		mlx_destroy_image(h->img.mlx, h->img3.img);
	if (h->img_verif > 4)
		mlx_destroy_image(h->img.mlx, h->img4.img);
	if (h->img_verif > 5)
		mlx_destroy_image(h->img.mlx, h->img6.img);
	if (h->img_verif > 6)
		mlx_destroy_image(h->img.mlx, h->img5.img);
	mlx_destroy_display(h->img.mlx);
	free(h->img.mlx);
}

void	ft_destroy_img_end(t_h *h)
{
	mlx_destroy_image(h->img.mlx, h->img.img);
	if (h->img_verif > 2)
		mlx_destroy_image(h->img.mlx, h->img2.img);
	if (h->img_verif > 3)
		mlx_destroy_image(h->img.mlx, h->img3.img);
	if (h->img_verif > 4)
		mlx_destroy_image(h->img.mlx, h->img4.img);
	if (h->img_verif > 5)
		mlx_destroy_image(h->img.mlx, h->img6.img);
	if (h->img_verif > 6)
		mlx_destroy_image(h->img.mlx, h->img5.img);
	if (h->save == 0)
		mlx_destroy_window(h->img.mlx, h->img.mlx_win);
	mlx_destroy_display(h->img.mlx);
	free(h->img.mlx);
}

void	ft_start(t_h *h, int *screensizex, int *screensizey)
{
	h->img.mlx = mlx_init();
	mlx_get_screen_size(h->img.mlx, screensizex, screensizey);
	ft_init_h(h, *screensizex, *screensizey);
}

void	ft_player(t_h *h)
{
	int	screensizex;
	int	screensizey;

	ft_start(h, &screensizex, &screensizey);
	wall(h);
	if (h->save == 0)
		h->img.mlx_win = mlx_new_window(h->img.mlx,
				h->s.reso[0], h->s.reso[1], "");
	h->img.img = mlx_new_image(h->img.mlx, h->s.reso[0], h->s.reso[1]);
	h->img.addr = mlx_get_data_addr(h->img.img,
			&h->img.bits_per_pixel, &h->img.line_length, &h->img.endian);
	if (h->save == 0)
	{
		mlx_hook(h->img.mlx_win, 2, 1L << 0, press, h);
		mlx_hook(h->img.mlx_win, 3, 1L << 1, release, h);
		mlx_hook(h->img.mlx_win, 33, 1L << 17, end, h);
	}
	else
		rien(h);
	mlx_loop_hook(h->img.mlx, rien, h);
	mlx_loop(h->img.mlx);
	ft_destroy_img_end(h);
}
