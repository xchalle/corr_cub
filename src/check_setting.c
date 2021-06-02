/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:02 by xchalle           #+#    #+#             */
/*   Updated: 2021/05/25 10:10:19 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_fln(t_h *h, int j)
{
	int	i;

	i = h->s.max - 1;
	while (h->s.array[j][i] == ' ')
		i--;
	return (i);
}

int	ft_flm(t_h *h, int j)
{
	int	i;

	i = 0;
	while (h->s.array[j][i] == ' ')
		i++;
	return (i);
}

void	check_map2_2(t_h *h, int i, int j, char c)
{
	while (i < h->s.max - 1)
	{
		if ((ft_charset_tot(h->s.array[j][i]) == 1 && c == ' ') ||
				(h->s.array[j][i] == ' ' && ft_charset_tot(c) == 1))
		{
			write(2, "Error\nMap not valid\n", 20);
			ft_free_struct(h);
			exit(EXIT_FAILURE);
		}
		if ((ft_charset_tot(h->s.array[j][i]) == 1 && h->s.array[j - 1][i]
					&& h->s.array[j - 1][i] == ' ') || (ft_charset_tot(h->
							s.array[j][i]) == 1 && h->s.array[j + 1][i]
						&& h->s.array[j + 1][i] == ' '))
		{
			write(2, "Error\nMap not valid\n", 20);
			ft_free_struct(h);
			exit(EXIT_FAILURE);
		}
		c = h->s.array[j][i];
		i++;
	}
	check_map3(h);
}

void	check_map2_1(t_h *h)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 1;
	while (j < h->s.i)
	{
		i = 0;
		c = h->s.array[j][0];
		check_map2_2(h, i, j, c);
		if (ft_charset_tot(h->s.array[j][ft_flm(h, j)]) == 1)
		{
			write(2, "Error\nMap not valid\n", 20);
			ft_free_struct(h);
			exit(EXIT_FAILURE);
		}
		if (ft_charset_tot(h->s.array[j][ft_fln(h, j)]) == 1)
		{
			write(2, "Error\nMap not valid\n", 20);
			ft_free_struct(h);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	check_map2(t_h *h)
{
	int	i;

	i = 0;
	while (i < h->s.max)
	{
		if (ft_charset_tot(h->s.array[0][i]) == 1)
		{
			write(2, "Error\nMap not valid\n", 20);
			ft_free_struct(h);
			exit(EXIT_FAILURE);
		}
		if (ft_charset_tot(h->s.array[h->s.i - 1][i]) == 1)
		{
			write(2, "Error\nMap not valid\n", 20);
			ft_free_struct(h);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (h->s.chara == 0)
	{
		write(2, "Error\nNo player start\n", 22);
		ft_free_struct(h);
		exit(-1);
	}
}
