/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:43 by xchalle           #+#    #+#             */
/*   Updated: 2021/04/17 17:11:41 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_verif3(t_h *h)
{
	if (h->s.so_verif != 1)
	{
		write(2, "Error\nNo south wall or more than one occurence\n", 47);
		ft_free_struct(h);
		exit(-1);
	}
	if (h->s.no_verif != 1)
	{
		write(2, "Error\nNo north wall or more than one occurence\n", 47);
		ft_free_struct(h);
		exit(-1);
	}
	if (h->s.we_verif != 1)
	{
		write(2, "Error\nNo west wall or more than one occurence\n", 46);
		ft_free_struct(h);
		exit(-1);
	}
	if (h->s.ea_veri != 1)
	{
		write(2, "Error\nNo east wall or more than one occurence\n", 46);
		ft_free_struct(h);
		exit(-1);
	}
}

void	check_verif2(t_h *h)
{
	if (h->s.floor_verif != 1)
	{
		write(2, "Error\nNo floor color or appear more than one time\n", 50);
		ft_free_struct(h);
		exit(-1);
	}
	if (h->s.ceiling_verif != 1)
	{
		write(2, "Error\nNo ceiling color or appear more than one time\n", 52);
		ft_free_struct(h);
		exit(-1);
	}
	if (h->s.reso_verif != 1)
	{
		write(2, "Error\nNot the right number of resolution\n", 41);
		ft_free_struct(h);
		exit(-1);
	}
}

int		check_verif(t_h *h)
{
	check_verif2(h);
	check_verif3(h);
	if (h->s.s_verif != 1)
	{
		write(2, "Error\nNo sprite or more than one occurence\n", 43);
		ft_free_struct(h);
		exit(-1);
	}
	if (h->map_verif != 1)
	{
		write(2, "Error\nNo map or wrong position in the file\n", 43);
		ft_free_struct(h);
		exit(-1);
	}
	check_color_range(h);
	return (0);
}

int		check_verif_soft(t_h *h)
{
	if (h->s.floor_verif == 0)
		return (1);
	if (h->s.ceiling_verif == 0)
		return (1);
	if (h->s.reso_verif == 0)
		return (1);
	if (h->s.so_verif == 0)
		return (1);
	if (h->s.no_verif == 0)
		return (1);
	if (h->s.we_verif == 0)
		return (1);
	if (h->s.ea_veri == 0)
		return (1);
	if (h->s.s_verif == 0)
		return (1);
	return (0);
}

void	check_color_range(t_h *h)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (h->s.floor[i] > 255 || h->s.floor[i] < 0)
		{
			write(2, "Error\nA floor color is not in the range\n", 40);
			ft_free_struct(h);
			exit(-1);
		}
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (h->s.ceiling[i] > 255 || h->s.ceiling[i] < 0)
		{
			write(2, "Error\nA ceiling color is not in the range\n", 42);
			ft_free_struct(h);
			exit(-1);
		}
		i++;
	}
}
