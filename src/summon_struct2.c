/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   summon_struct2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:07:20 by xchalle           #+#    #+#             */
/*   Updated: 2021/05/25 10:13:59 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	summon_r(char *str, t_h *h, int i)
{
	if (str[i] == 'R' && h->s.reso_verif == 1)
		h->s.reso_verif = 2;
	if (str[i] == 'R' && h->s.reso_verif == 0)
	{
		i++;
		while (str[i] == ' ' || str[i] == ',')
			i++;
		if ((str[i] != ' ' && str[i] != ',') && (str[i] < '0' || str[i] > '9'))
			error_struct_2(h, i, str, 5);
		h->s.reso[0] = ft_atoi(str + i);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ' ' || str[i] == ',')
			i++;
		if ((str[i] != ' ' && str[i] != ',') && (str[i] < '0' || str[i] > '9'))
			error_struct_2(h, i, str, 5);
		h->s.reso[1] = ft_atoi(str + i);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ' ')
			i++;
		error_struct_2(h, i, str, 0);
		h->s.reso_verif = 1;
	}
}

void	summon_f2(char *str, t_h *h, int i)
{
	if ((str[i] != ' ' && str[i] != ',') && (str[i] < '0' || str[i] > '9'))
		error_struct_2(h, i, str, 4);
	h->s.floor[1] = ft_atoi(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' || str[i] == ',')
		i++;
	if ((str[i] != ' ' && str[i] != ',') && (str[i] < '0' || str[i] > '9'))
		error_struct_2(h, i, str, 4);
	h->s.floor[2] = ft_atoi(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	error_struct_2(h, i, str, 1);
	h->s.floor_verif = 1;
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
			error_struct_2(h, i, str, 4);
		h->s.floor[0] = ft_atoi(str + i);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ' ' || str[i] == ',')
			i++;
		summon_f2(str, h, i);
	}
}

void	summon_c2(char *str, t_h *h, int i)
{
	if ((str[i] != ' ' && str[i] != ',') && (str[i] < '0' || str[i] > '9'))
		error_struct_2(h, i, str, 3);
	h->s.ceiling[1] = ft_atoi(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' || str[i] == ',')
		i++;
	if ((str[i] != ' ' && str[i] != ',') && (str[i] < '0' || str[i] > '9'))
		error_struct_2(h, i, str, 3);
	h->s.ceiling[2] = ft_atoi(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	error_struct_2(h, i, str, 2);
	h->s.ceiling_verif = 1;
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
			error_struct_2(h, i, str, 3);
		h->s.ceiling[0] = ft_atoi(str + i);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ' ' || str[i] == ',')
			i++;
		summon_c2(str, h, i);
	}
}
