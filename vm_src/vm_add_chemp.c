/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_add_chemp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:06:37 by iseletsk          #+#    #+#             */
/*   Updated: 2018/06/05 16:11:55 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_chemp	*s_create_chemp(int nbr, int color)
{
	t_chemp		*chemp;
	int			i;

	i = 0;
	chemp = malloc(sizeof(t_chemp));
	chemp->nbr[0] = (nbr >> 24) & 255;
	chemp->nbr[1] = ((nbr << 8) >> 24) & 255;
	chemp->nbr[2] = ((nbr << 16) >> 24) & 255;
	chemp->nbr[3] = ((nbr << 24) >> 24) & 255;
	chemp->color = color;
	chemp->cycl_live = 0;
	chemp->live_icp = 0;
	chemp->next = 0;
	chemp->size = 0;
	return (chemp);
}

t_chemp			*vm_add_chemp(void)
{
	int			i;
	int			color;
	t_chemp		*chemp;
	t_chemp		*b_chemp;

	i = -1;
	color = 0;
	b_chemp = s_create_chemp(g_flag.zerro, color++);
	while (++i < g_flag.nbr_ch)
	{
		chemp = b_chemp;
		if (!b_chemp)
		{
			b_chemp = s_create_chemp(-g_flag.nbr[i], color++);
			continue;
		}
		while (chemp->next)
			chemp = chemp->next;
		chemp->next = s_create_chemp(-g_flag.nbr[i], color++);
	}
	return (b_chemp);
}
