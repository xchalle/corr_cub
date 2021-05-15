/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   summon_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:07:26 by xchalle           #+#    #+#             */
/*   Updated: 2021/04/17 15:02:23 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	summon_so(char *str, t_s *s, int i)
{
	int j;

	j = 0;
	if (str[i] == 'S' && str[i + 1] == 'O' && s->so_verif == 1)
		s->so_verif = 2;
	if (str[i] == 'S' && str[i + 1] == 'O' && s->so_verif == 0)
	{
		i += 2;
		while (str[i] == ' ')
			i++;
		s->stocki = i;
		while (str[i] != '\0' && str[i] != '\n')
		{
			i++;
			j++;
		}
		if (!(s->so = malloc(sizeof(char) * (j + 1))))
			return ;
		i = s->stocki;
		j = 0;
		while (str[i] != '\0' && str[i] != '\n')
			s->so[j++] = str[i++];
		s->so[j] = '\0';
		s->so_verif = 1;
	}
}

void	summon_no(char *str, t_s *s, int i)
{
	int j;

	j = 0;
	if (str[i] == 'N' && str[i + 1] == 'O' && s->no_verif == 1)
		s->no_verif = 2;
	if (str[i] == 'N' && str[i + 1] == 'O' && s->no_verif == 0)
	{
		i += 2;
		while (str[i] == ' ')
			i++;
		s->stocki = i;
		while (str[i] != '\0' && str[i] != '\n')
		{
			i++;
			j++;
		}
		if (!(s->no = malloc(sizeof(char) * (j + 1))))
			return ;
		i = s->stocki;
		j = 0;
		while (str[i] != '\0' && str[i] != '\n')
			s->no[j++] = str[i++];
		s->no[j] = '\0';
		s->no_verif = 1;
	}
}

void	summon_we(char *str, t_s *s, int i)
{
	int j;

	j = 0;
	if (str[i] == 'W' && str[i + 1] == 'E' && s->we_verif == 1)
		s->we_verif = 2;
	if (str[i] == 'W' && str[i + 1] == 'E' && s->we_verif == 0)
	{
		i += 2;
		while (str[i] == ' ')
			i++;
		s->stocki = i;
		while (str[i] != '\0' && str[i] != '\n')
		{
			i++;
			j++;
		}
		if (!(s->we = malloc(sizeof(char) * (j + 1))))
			return ;
		i = s->stocki;
		j = 0;
		while (str[i] != '\0' && str[i] != '\n')
			s->we[j++] = str[i++];
		s->we[j] = '\0';
		s->we_verif = 1;
	}
}

void	summon_ea(char *str, t_s *s, int i)
{
	int j;

	j = 0;
	if (str[i] == 'E' && str[i + 1] == 'A' && s->ea_veri == 1)
		s->ea_veri = 2;
	if (str[i] == 'E' && str[i + 1] == 'A' && s->ea_veri == 0)
	{
		i += 2;
		while (str[i] == ' ')
			i++;
		s->stocki = i;
		while (str[i] != '\0' && str[i] != '\n')
		{
			i++;
			j++;
		}
		if (!(s->ea = malloc(sizeof(char) * (j + 1))))
			return ;
		i = s->stocki;
		j = 0;
		while (str[i] != '\0' && str[i] != '\n')
			s->ea[j++] = str[i++];
		s->ea[j] = '\0';
		s->ea_veri = 1;
	}
}

void	summon_s(char *str, t_s *s, int i)
{
	int j;

	j = 0;
	if (str[i] == 'S' && str[i + 1] == ' ' && s->s_verif == 1)
		s->s_verif = 2;
	if (str[i] == 'S' && str[i + 1] == ' ' && s->s_verif == 0)
	{
		i += 2;
		while (str[i] == ' ')
			i++;
		s->stocki = i;
		while (str[i] != '\0' && str[i] != '\n')
		{
			i++;
			j++;
		}
		if (!(s->s = malloc(sizeof(char) * (j + 1))))
			return ;
		i = s->stocki;
		j = 0;
		while (str[i] != '\0' && str[i] != '\n')
			s->s[j++] = str[i++];
		s->s[j] = '\0';
		s->s_verif = 1;
	}
}
