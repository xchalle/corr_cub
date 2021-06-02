/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   summon_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:07:07 by xchalle           #+#    #+#             */
/*   Updated: 2021/05/25 10:13:39 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init(t_h *h, char *str)
{
	if ((size_t)h->s.max < ft_strlen(str))
		h->s.max = ft_strlen(str);
}

void	parsing_map(t_h *h, int fd, char *str, int i)
{
	int		o;
	char	*stockstr;
	char	*freestr;
	int		ret;

	o = 0;
	i++;
	init(h, str);
	stockstr = str;
	ret = get_next_line(fd, &str);
	if (ret == 1)
	{
		parsing_map(h, fd, str, i);
		str = stockstr;
	}
	else
	{
		alloc_array(h, i);
		freestr = str;
		str = stockstr;
		free(freestr);
	}
	write_map(str, o, i, h);
	free(stockstr);
}

void	alloc_array(t_h *h, int i)
{
	h->s.array = malloc(sizeof(char *) * (i + 1));
	if (!(h->s.array))
		return ;
	while (h->s.i <= i)
	{
		h->s.array[h->s.i] = malloc(sizeof(char) * (h->s.max + 1));
		if (!(h->s.array[h->s.i]))
			return ;
		h->s.i++;
	}
	h->map_verif = 1;
}

void	write_map(char *str, int o, int i, t_h *h)
{
	while (str[o] && (str[o] != '\n' || str[o] != '\0') && str[0] != 0)
	{
		if (str[o] == '2')
			h->sprt++;
		h->s.array[i][o] = str[o];
		if (ft_charset(str[o]))
		{
			if (h->s.chara != 0)
				h->s.chara_verif = 1;
			h->s.posi = i;
			h->s.posj = o;
			h->s.chara = str[o];
		}
		o++;
	}
	while (o < h->s.max && str[0])
		h->s.array[i][o++] = ' ';
	h->s.array[i][o] = '\0';
}
