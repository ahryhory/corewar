/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:32:28 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/17 19:56:41 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		do_ld(t_con *con, int index, int *n, t_proc *proc)
{
	int		tmp;
	int		val;
	printf("COMMAND: ld\n");

	index = get_index(index, 2); // because this command has codage
	if (n[0] == 2)
	{
		val = get_nbr(con, index, 4);
		proc->r[con->mem[get_index(index, 4)].byte] = val;
	}
	else
	{
		tmp =  get_nbr(con, index, 2) % IDX_MOD;
		con->mem[index].byte = ((tmp << 16) >> 24) & 255;
		con->mem[get_index(index, 1)].byte = ((tmp << 24) >> 24) & 255;
		val = get_nbr(con, get_index(proc->index, tmp), 4);
		proc->r[con->mem[get_index(index, 2)].byte] = val;
	}
	if (val == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
