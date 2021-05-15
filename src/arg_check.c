/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:03:42 by xchalle           #+#    #+#             */
/*   Updated: 2021/04/06 19:13:41 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	trim(long double *di, double *j)
{
	int i;

	i = *di;
	if (*di < 0)
	{
		*j -= i;
		*di -= i;
	}
}

void	check_arg(int argc, char **argv, t_h *h)
{
	if (argc == 3 && ft_strncmp(argv[2], "--save", ft_strlen(argv[2]))
			== 0 && ft_strlen("--save") == ft_strlen(argv[2]))
	{
		h->save = 1;
	}
	else
	{
		write(2, "Error\nWrong arguments or number of them\n", 40);
		exit(EXIT_FAILURE);
	}
}

void	arg_check(int argc, char **argv, t_h *h)
{
	char	str[4];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (argc < 2 || argc >= 3)
		check_arg(argc, argv, h);
	while (argv[1][i])
		i++;
	i -= 4;
	while (argv[1][i])
		str[j++] = argv[1][i++];
	if (ft_memcmp(str, ".cub", 4) != 0)
	{
		write(2, "Error\nNo .cub extension\n", 24);
		ft_free_struct(h);
		exit(EXIT_FAILURE);
	}
}
