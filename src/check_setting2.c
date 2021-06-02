/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_setting2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:03:54 by xchalle           #+#    #+#             */
/*   Updated: 2021/05/25 10:09:58 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_map3(t_h *h)
{
	int	i;

	i = 0;
	while (i < h->s.i)
	{
		if (charset_str(h->s.array[i]) == 0)
		{
			write(2, "Error\nMap not valid\n", 20);
			ft_free_struct(h);
			exit(-1);
		}
		i++;
	}
	if (h->s.chara_verif == 1)
	{
		write(2, "Error\n2 start for player\n", 25);
		ft_free_struct(h);
		exit(-1);
	}
}
