/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:33:49 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/18 18:42:09 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	nbr_equ(int *nbr1, int *nbr2)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (nbr1[i] != nbr2[i])
			return (0);
		i++;
	}
	return (1);
}

void		do_live(t_con *con, int index, t_proc *proc)
{
	int		nbr[4];
	int		i;

	printf("COMMAND: live\n");
	if (proc->live <= 1)
		proc->live++;
	nbr[0] = con->mem[index].byte;
	nbr[1] = con->mem[get_index(index, 1)].byte;
	nbr[2] = con->mem[get_index(index, 2)].byte;
	nbr[3] = con->mem[get_index(index, 3)].byte;
	i = -1;
	while (++i < 4)
	{
		if(nbr[i] == con->mem[index].chemp->nbr[i])
		{
			con->mem[index].chemp->live++;
			con->mem[index].chemp->live_icp++;
		}
	}
}
