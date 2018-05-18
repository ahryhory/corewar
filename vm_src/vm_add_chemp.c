/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_add_chemp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:06:37 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/18 18:33:34 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_chemp	*s_create_chemp(int nbr)
{
	t_chemp	*chemp;
	int		i;

	chemp = malloc(sizeof(t_chemp));
	chemp->nbr[0] = (nbr >> 24) & 255;
	chemp->nbr[1] = ((nbr << 8) >> 24) & 255;
	chemp->nbr[2] = ((nbr << 16) >> 24) & 255;
	chemp->nbr[3] = ((nbr << 24) >> 24) & 255;
	chemp->live = 0;
	chemp->live_icp = 0;
	chemp->next = 0;
	return (chemp);
}

t_chemp	*vm_add_chemp(int nbr)
{
	int		i;
	t_chemp	*chemp;
	t_chemp	*b_chemp;

	i = -1;
	b_chemp = 0;
	while (nbr--)
	{
		chemp = b_chemp;
		if (!b_chemp)
		{
			b_chemp = s_create_chemp(i--);
			continue;
		}
		while (chemp->next)
			chemp = chemp->next;
		chemp->next = s_create_chemp(i--);
	}
	return (b_chemp);
}
