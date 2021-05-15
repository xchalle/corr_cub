/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcent_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:05:43 by xchalle           #+#    #+#             */
/*   Updated: 2021/04/20 20:32:03 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	pourcent_img_vert(t_h *h)
{
	double	val;

	val = fmod(h->p.hity_vert, CUB);
	if (h->p.fov > 1.5 * (M_PI) || h->p.fov < (M_PI / 2))
		val = CUB - val;
	h->pourcent = val;
}

void	pourcent_img_horz(t_h *h)
{
	double	val;

	val = fmod(h->p.hitx_horz, CUB);
	if (h->p.fov > (M_PI) || h->p.fov < 0)
		val = CUB - val;
	h->pourcent = val;
}
