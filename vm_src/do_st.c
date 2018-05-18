/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:32:37 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/17 19:57:58 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_st(t_con *con, int index, int *n, t_proc *proc)
{
	int		coord;
	int		indx;
	int		tmp;

	printf("COMMAND: st, %d\n", n[1]);
	index = get_index(index, 2);
	if (n[1] == 3)
	{
		indx = get_index(proc->index, get_nbr(con, get_index(index, 1), 2) % IDX_MOD);
		tmp = proc->r[con->mem[index].byte];
		con->mem[indx].byte = (tmp >> 24) & 255;
		con->mem[get_index(indx, 1)].byte = ((tmp << 8) >> 24) & 255;
		con->mem[get_index(indx, 2)].byte = ((tmp << 16) >> 24) & 255;
		con->mem[get_index(indx, 3)].byte = ((tmp << 24) >> 24) & 255;
	}
	else
		proc->r[con->mem[get_index(index, 1)].byte] = proc->r[con->mem[index].byte];
}
