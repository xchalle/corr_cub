/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   summon_struct3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:44:32 by xchalle           #+#    #+#             */
/*   Updated: 2021/05/25 10:14:10 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	chars(char c)
{
	if (c == '1' || c == '2' || c == '0')
		return (1);
	return (0);
}

int	summon_bin(char *str, t_h *h)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (ft_strlen(str) == (unsigned int)i)
		return (0);
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != '2' && str[i] != ' ')
			return (0);
		i++;
	}
	free(str);
	write(2, "Error\nWrong map position\n", 25);
	ft_free_struct(h);
	exit(-1);
}
