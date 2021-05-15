/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:06:36 by xchalle           #+#    #+#             */
/*   Updated: 2021/01/18 12:08:19 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_modif(char const *s, char const *s1, char const *s2, int *o)
{
	int		i;
	int		k;
	char	*str;
	int		l;
	int		m;

	i = 0;
	k = 0;
	l = ft_strlen(s);
	m = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (l + m) + 1)))
		return (0);
	while (s1[i] && *o != 0)
		str[k++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		str[k] = s2[i];
		k++;
		i++;
	}
	str[k] = '\0';
	*o = 1;
	return (str);
}
