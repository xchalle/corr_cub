/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:15:15 by xchalle           #+#    #+#             */
/*   Updated: 2021/05/25 10:15:19 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	error_struct_2(t_h *h, int i, char *str, int e)
{
	if (str[i] != '\0' && e == 0)
	{
		write(2, "Error\nresolution is not valid\n", 30);
		ft_free_struct(h);
		free(str);
		exit(-1);
	}
	if (str[i] != '\0' && e == 1)
	{
		write(2, "Error\nfloor is not valid\n", 25);
		ft_free_struct(h);
		free(str);
		exit(-1);
	}
	if (str[i] != '\0' && e == 2)
	{
		write(2, "Error\nceiling is not valid\n", 27);
		ft_free_struct(h);
		free(str);
		exit(-1);
	}
	error_struct_2bis(h, str, e);
}

void	error_struct_2bis(t_h *h, char *str, int e)
{
	if (e == 3)
	{
		write(2, "Error\nceiling is not valid\n", 27);
		ft_free_struct(h);
		free(str);
		exit(-1);
	}
	if (e == 4)
	{
		write(2, "Error\nfloor is not valid\n", 25);
		ft_free_struct(h);
		free(str);
		exit(-1);
	}
	if (e == 5)
	{
		write(2, "Error\nresolution is not valid\n", 30);
		ft_free_struct(h);
		free(str);
		exit(-1);
	}
}

void	check_int_reso(t_h *h)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (h->s.reso[i] > 2147483647 || h->s.reso[i] < 1)
		{
			write(2, "Error\nResolution is not valid\n", 30);
			ft_free_struct(h);
			exit(-1);
		}
		i++;
	}
}

int	count_str(char *str, int i, int j)
{
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
		j++;
	}
	return (j);
}
