/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   summon_minimap2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:06:59 by xchalle           #+#    #+#             */
/*   Updated: 2021/04/06 19:16:54 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	summon_map(char *str, int fd, t_h *h)
{
	int	i;

	i = 0;
	h->s.max = 0;
	h->s.i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '0' || str[i] == '1'))
	{
		if (str[i] == '0' || str[i] == '1')
		{
			parsing_map(h, fd, str, -1);
			return ;
		}
		i++;
	}
	free(str);
}

int		ft_charset(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int		ft_charset_tot(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '2' || c == '0')
		return (1);
	return (0);
}

int		charset_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != 'N' &&
				str[i] != 'S' && str[i] != 'E' && str[i] != 'W'
				&& str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
