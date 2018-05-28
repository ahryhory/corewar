/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:33:49 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/27 15:19:13 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		do_live(t_con *con, int index, t_proc *proc)
{
	int		nbr[4];
	int		i;
//	int				l;

	printf("COMMAND: live\n");
	con->live++;
	if (proc->live <= 1)
		proc->live++;
	nbr[0] = con->mem[get_index(index, 1)].byte;
	nbr[1] = con->mem[get_index(index, 2)].byte;
	nbr[2] = con->mem[get_index(index, 3)].byte;
	nbr[3] = con->mem[get_index(index, 4)].byte;
	i = -1;
	while (++i < 4)
	{
		if(nbr[i] != con->mem[index].chemp->nbr[i])
			return ;
	}
	con->mem[index].chemp->cycl_live = con->cycl;
	con->mem[index].chemp->live_icp++;
//	printf("chemp: %d, live: %d\n", (char)con->mem[index].chemp->nbr[3],
//			con->mem[index].chemp->live_icp);
}
