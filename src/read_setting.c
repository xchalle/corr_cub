/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:06:14 by xchalle           #+#    #+#             */
/*   Updated: 2021/05/25 10:13:00 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_map(t_h *h)
{
	int	j;

	j = 0;
	while (j < h->s.i)
	{
		if (h->s.array[j][0] == '\0')
		{
			write(2, "Error\nMap not valid\n", 20);
			ft_free_struct(h);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	read_setting(t_h *h, char *file)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nOuverture file\n", 21);
		close(fd);
		exit(-1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		if (check_verif_soft(h) == 1)
		{
			switch_setting(line, h);
			free(line);
		}
		else
			summon_map(line, fd, h);
	}
	free(line);
	close(fd);
}
