/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   summon_struct2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:07:20 by xchalle           #+#    #+#             */
/*   Updated: 2021/04/17 14:00:34 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	summon_r(char *str, t_s *s, int i)
{
	if (str[i] == 'R' && s->reso_verif == 1)
		s->reso_verif = 2;
	if (str[i] == 'R' && s->reso_verif == 0)
	{
		i++;
		while (str[i] == ' ' || str[i] == ',')
			i++;
		if ((str[i] != ' ' && str[i] != ',') && (str[i] < '0' || str[i] > '9'))
			return ;
		s->reso[0] = ft_atoi(str + i);
		i = i + ft_nbrlen(s->reso[0]);
		while (str[i] == ' ' || str[i] == ',')
			i++;
		if ((str[i] != ' ' && str[i] != ',') && (str[i] < '0' || str[i] > '9'))
			return ;
		while (str[i] < '0' || str[i] > '9')
			i++;
		s->reso[1] = ft_atoi(str + i);
		s->reso_verif = 1;
	}
}

void	summon_f2(char *str, t_s *s, int i)
{
	if ((str[i] != ' ' && str[i] != ',') && (str[i] < '0' || str[i] > '9'))
	{
		s->floor_verif = 0;
		return ;
	}
	s->floor[1] = ft_atoi(str + i);
	i = i + ft_nbrlen(s->floor[1]);
	while (str[i] == ' ' || str[i] == ',')
		i++;
	if ((str[i] != ' ' && str[i] != ',') && (str[i] < '0' || str[i] > '9'))
	{
		s->floor_verif = 0;
		return ;
	}
	s->floor[2] = ft_atoi(str + i);
	s->floor_verif = 1;
}

void	summon_f(char *str, t_h *h, int i)
{
	if (str[i] == 'F' && h->s.floor_verif == 1)
		h->s.floor_verif = 2;
	if (str[i] == 'F' && h->s.floor_verif == 0)
	{
		i++;
		while (str[i] == ' ' || str[i] == ',')
			i++;
		if ((str[i] != ' ' && str[i] != ',') && (str[i] < '0' || str[i] > '9'))
		{
			h->s.floor_verif = 0;
			return ;
		}
		h->s.floor[0] = ft_atoi(str + i);
		i = i + ft_nbrlen(h->s.floor[0]);
		while (str[i] == ' ' || str[i] == ',')
			i++;
		summon_f2(str, &h->s, i);
	}
}

void	summon_c2(char *str, t_s *s, int i)
{
	if ((str[i] != ' ' && str[i] != ',') && (str[i] < '0' || str[i] > '9'))
	{
		s->ceiling_verif = 0;
		return ;
	}
	s->ceiling[1] = ft_atoi(str + i);
	i = i + ft_nbrlen(s->ceiling[1]);
	while (str[i] == ' ' || str[i] == ',')
		i++;
	if ((str[i] != ' ' && str[i] != ',') && (str[i] < '0' || str[i] > '9'))
	{
		s->ceiling_verif = 0;
		return ;
	}
	s->ceiling[2] = ft_atoi(str + i);
	s->ceiling_verif = 1;
}

void	summon_c(char *str, t_h *h, int i)
{
	if (str[i] == 'C' && h->s.ceiling_verif == 1)
		h->s.ceiling_verif = 2;
	if (str[i] == 'C' && h->s.ceiling_verif == 0)
	{
		i++;
		while (str[i] == ' ' || str[i] == ',')
			i++;
		if ((str[i] != ' ' && str[i] != ',') && (str[i] < '0' || str[i] > '9'))
		{
			h->s.ceiling_verif = 0;
			return ;
		}
		h->s.ceiling[0] = ft_atoi(str + i);
		i = i + ft_nbrlen(h->s.ceiling[0]);
		while (str[i] == ' ' || str[i] == ',')
			i++;
		summon_c2(str, &h->s, i);
	}
}
