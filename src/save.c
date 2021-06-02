/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:06:46 by xchalle           #+#    #+#             */
/*   Updated: 2021/05/25 10:13:11 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	write_bmp2(int fd, t_h *h)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 + h->s.reso[0] * h->s.reso[1];
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &h->s.reso[0], 4);
	write(fd, &h->s.reso[1], 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &h->img.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void	ft_destroy(t_h *h)
{
	ft_destroy_img_end(h);
	ft_free_struct(h);
}

void	write_bmp(t_h *h)
{
	int	fd;
	int	y;
	int	x;

	y = h->s.reso[1];
	fd = open("save.bmp", O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1)
	{
		write(2, "Error\nOpen bmp\n", 15);
		ft_destroy(h);
		exit(-1);
	}
	write_bmp2(fd, h);
	while (y >= 0)
	{
		x = 0;
		while (x < h->s.reso[0])
		{
			write(fd, &h->img.addr[(y * h->img.line_length + x
					* (h->img.bits_per_pixel / 8))], 4);
			x++;
		}
		y--;
	}
	close(fd);
}
