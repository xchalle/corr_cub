/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:05:28 by xchalle           #+#    #+#             */
/*   Updated: 2021/05/25 10:11:46 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_line(char *str, t_h *h, int i)
{
	if ((str[i] == 'S' && str[i + 1] == 'O') || chars(str[i] == 1))
		return ;
	if ((str[i] == 'S' && str[i + 1] == ' ') || chars(str[i] == 1))
		return ;
	if ((str[i] == 'N' && str[i + 1] == 'O') || chars(str[i] == 1))
		return ;
	if ((str[i] == 'W' && str[i + 1] == 'E') || chars(str[i] == 1))
		return ;
	if ((str[i] == 'E' && str[i + 1] == 'A') || chars(str[i] == 1))
		return ;
	if ((str[i] == 'F' && str[i + 1] == ' ') || chars(str[i] == 1))
		return ;
	if ((str[i] == 'C' && str[i + 1] == ' ') || chars(str[i] == 1))
		return ;
	if ((str[i] == 'R' && str[i + 1] == ' ') || chars(str[i] == 1))
		return ;
	ft_free_struct(h);
	free(str);
	write(2, "Error\nUnexpected line in .cub\n", 30);
	exit(-1);
}

void	switch_setting(char *str, t_h *h)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 0)
		return ;
	check_line(str, h, i);
	if (h->count < 8)
		summon_bin(str, h);
	h->count++;
	summon_so(str, &h->s, i);
	summon_no(str, &h->s, i);
	summon_we(str, &h->s, i);
	summon_ea(str, &h->s, i);
	summon_s(str, &h->s, i);
	summon_f(str, h, i);
	summon_c(str, h, i);
	summon_r(str, h, i);
}

void	ft_free_struct(t_h *h)
{
	int	i;

	i = 0;
	if (h->map_verif == 1)
	{
		while (i < h->s.i)
		{
			free(h->s.array[i]);
			i++;
		}
		free(h->s.array);
	}
	if (h->s.no_verif != 0)
		free(h->s.no);
	if (h->s.so_verif != 0)
		free(h->s.so);
	if (h->s.we_verif != 0)
		free(h->s.we);
	if (h->s.ea_veri != 0)
		free(h->s.ea);
	if (h->s.s_verif != 0)
		free(h->s.s);
	if (h->u_verif != 0)
		free(h->u);
}

void	main_init(t_h *h)
{
	h->save = 0;
	h->map_verif = 0;
	h->img_verif = 8;
	h->u_verif = 0;
	h->s.i = 0;
	h->i = 0;
	h->s.chara = 0;
	h->sprt = 0;
	h->s.floor_verif = 0;
	h->s.ceiling_verif = 0;
	h->s.so_verif = 0;
	h->s.no_verif = 0;
	h->s.we_verif = 0;
	h->s.ea_veri = 0;
	h->s.s_verif = 0;
	h->s.reso_verif = 0;
	h->s.chara_verif = 0;
	h->count = 0;
}

int	main(int argc, char **argv)
{
	t_h	h;

	main_init(&h);
	arg_check(argc, argv, &h);
	read_setting(&h, argv[1]);
	check_verif(&h);
	check_map(&h);
	check_map2(&h);
	check_map2_1(&h);
	h.u = malloc(sizeof(t_u) * h.sprt + 1);
	if (!(h.u))
	{
		ft_free_struct(&h);
		write(2, "Error\nMalloc sprite failed\n", 27);
		exit(EXIT_FAILURE);
	}
	h.longe = h.s.max;
	if (h.s.max < h.s.i)
		h.longe = h.s.i;
	h.u_verif = 1;
	ft_player(&h);
	ft_free_struct(&h);
	return (0);
}
