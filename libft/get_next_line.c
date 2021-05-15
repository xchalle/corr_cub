/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:45:54 by xchalle           #+#    #+#             */
/*   Updated: 2020/12/27 15:14:18 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char keeper[257][BUFFER_SIZE + 1] = {{0}};
	char		*wait;

	if (fd > 256 || fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	wait = NULL;
	if (keeper[fd][0] != 0 && ft_check(keeper[fd], '\n', BUFFER_SIZE) == 1)
	{
		if (!(*line = ft_strjoin_gnl(NULL, keeper[fd], '\n')))
			return (-1);
		ft_swap_gnl(keeper[fd], keeper[fd] + ft_strlen_gnl(keeper[fd], '\n'));
		return (1);
	}
	return (ft_termine_garcon(line, keeper[fd], wait, fd));
}

int		ft_termine_garcon(char **line, char *keeper, char *wait, int fd)
{
	int f;

	f = ft_read(fd, &wait);
	if (f == -1)
	{
		free(wait);
		return (-1);
	}
	if (!wait && f == 0)
	{
		if (!(*line = ft_strjoin_gnl(NULL, keeper, '\n')))
			return (-1);
		keeper[0] = 0;
		free(wait);
		return (0);
	}
	*line = ft_strjoin_gnl(keeper, wait, '\n');
	keeper = ft_swap_gnl(keeper, wait);
	free(wait);
	return (f);
}

int		ft_read(int fd, char **wait)
{
	char	*tmp;
	int		ret;
	char	*vid;

	if (!(tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	ret = 0;
	while ((ret = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		if (ft_check(tmp, '\n', ret) == 1)
		{
			vid = *wait;
			*wait = ft_strjoin_gnl(*wait, tmp, '\0');
			free(vid);
			free(tmp);
			return (1);
		}
		vid = *wait;
		*wait = ft_strjoin_gnl(*wait, tmp, '\0');
		free(vid);
	}
	free(tmp);
	return (ret);
}
