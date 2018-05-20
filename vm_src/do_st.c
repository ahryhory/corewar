/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:32:37 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/20 14:44:34 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_st(t_con *con, int index, unsigned int *n, t_proc *proc)
{
	int		coord;
	int		indx;
	int		tmp;

	printf("COMMAND: st\n");
	index = get_index(index, 2);
	if (n[1] == 3)
	{
		printf("%d\n", (short int)(get_nbr(con, get_index(index, 1), 2)));

		indx = get_index(proc->index,
				(short int)(get_nbr(con, get_index(index, 1), 2)) % IDX_MOD);
		printf("%d\n", indx);
		tmp = proc->r[con->mem[index].byte - 1];
		con->mem[indx].byte = (tmp >> 24) & 255;
		con->mem[get_index(indx, 1)].byte = ((tmp << 8) >> 24) & 255;
		con->mem[get_index(indx, 2)].byte = ((tmp << 16) >> 24) & 255;
		con->mem[get_index(indx, 3)].byte = ((tmp << 24) >> 24) & 255;
		printf("%d, %d, %d, %d\n", index, indx, tmp, con->mem[index].byte);
//		exit(0);
	}
	else
		proc->r[con->mem[get_index(index, 1)].byte] = proc->r[con->mem[index].byte];
}
