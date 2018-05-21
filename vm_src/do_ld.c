/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:32:28 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/21 18:06:02 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		do_ld(t_con *con, int index, unsigned int *n, t_proc *proc)
{
	int		tmp;
	int		val;
	printf("COMMAND: ld\n");

	index = get_index(index, 2); // because this command has codage
	if (n[0] == 2)
	{
		val = get_nbr(con, index, 4);
		proc->r[con->mem[get_index(index, 4)].byte - 1] = val;
	}
	else
	{
		tmp =  (short int)(get_nbr(con, index, 2)) % IDX_MOD;
		val = get_nbr(con, get_index(proc->index, tmp), 4);
		proc->r[con->mem[get_index(index, 2)].byte - 1] = val;
	}
	if (val == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
