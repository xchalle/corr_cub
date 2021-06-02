/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:07:35 by xchalle           #+#    #+#             */
/*   Updated: 2021/05/25 10:15:32 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	wall(t_h *h)
{
	h->img2.img = mlx_xpm_file_to_image(h->img.mlx,
			h->s.ea, &h->img2.x_img, &h->img2.y_img);
	if (!(h->img2.img))
	{
		write(2, "Error\nEast wall image not valid\n", 32);
		h->img_verif = 2;
		ft_destroy_img(h);
		ft_free_struct(h);
		exit(EXIT_FAILURE);
	}
	h->img2.addr = mlx_get_data_addr(h->img2.img,
			&h->img2.bits_per_pixel, &h->img2.line_length, &h->img2.endian);
	return (wall_we(h));
}

int	wall_we(t_h *h)
{
	h->img3.img = mlx_xpm_file_to_image(h->img.mlx,
			h->s.we, &h->img3.x_img, &h->img3.y_img);
	if (!(h->img3.img))
	{
		write(2, "Error\nWest wall image not valid\n", 32);
		h->img_verif = 3;
		ft_destroy_img(h);
		ft_free_struct(h);
		exit(EXIT_FAILURE);
	}
	h->img3.addr = mlx_get_data_addr(h->img3.img,
			&h->img3.bits_per_pixel, &h->img3.line_length, &h->img3.endian);
	return (wall_so(h));
}

int	wall_so(t_h *h)
{
	h->img4.img = mlx_xpm_file_to_image(h->img.mlx,
			h->s.so, &h->img4.x_img, &h->img4.y_img);
	if (!(h->img4.img))
	{
		write(2, "Error\nSouth wall image not valid\n", 33);
		h->img_verif = 4;
		ft_destroy_img(h);
		ft_free_struct(h);
		exit(EXIT_FAILURE);
	}
	h->img4.addr = mlx_get_data_addr(h->img4.img,
			&h->img4.bits_per_pixel, &h->img4.line_length, &h->img4.endian);
	return (wall_s(h));
}

int	wall_s(t_h *h)
{
	h->img6.img = mlx_xpm_file_to_image(h->img.mlx,
			h->s.s, &h->img6.x_img, &h->img6.y_img);
	if (!(h->img6.img))
	{
		write(2, "Error\nSprite image not valid\n", 29);
		h->img_verif = 5;
		ft_destroy_img(h);
		ft_free_struct(h);
		exit(EXIT_FAILURE);
	}
	h->img6.addr = mlx_get_data_addr(h->img6.img,
			&h->img6.bits_per_pixel, &h->img6.line_length, &h->img6.endian);
	return (wall_no(h));
}

int	wall_no(t_h *h)
{
	h->img5.img = mlx_xpm_file_to_image(h->img.mlx,
			h->s.no, &h->img5.x_img, &h->img5.y_img);
	if (!(h->img5.img))
	{
		write(2, "Error\nNorth wall image not valid\n", 33);
		h->img_verif = 6;
		ft_destroy_img(h);
		ft_free_struct(h);
		exit(EXIT_FAILURE);
	}
	h->img5.addr = mlx_get_data_addr(h->img5.img,
			&h->img5.bits_per_pixel, &h->img5.line_length, &h->img5.endian);
	return (1);
}
