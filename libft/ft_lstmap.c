/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:43:12 by xchalle           #+#    #+#             */
/*   Updated: 2020/11/23 17:50:49 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*p;

	if (!lst || !f)
		return (0);
	if (!(p = ft_lstnew((*f)(lst->content))))
	{
		ft_lstclear(&p, del);
		return (0);
	}
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&p, del);
			return (0);
		}
		ft_lstadd_back(&p, new);
		lst = lst->next;
	}
	return (p);
}
