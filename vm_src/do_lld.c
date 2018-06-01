/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:34:44 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/01 15:37:52 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		do_lld(t_con *con, int index, unsigned int *n, t_proc *proc)
{
	int				tmp;
	unsigned int	val;

	index = get_index(index, 2);
	if (n[0] == 2)
	{
		val = get_nbr(con, index, 4);
		proc->r[con->mem[get_index(index, 4)].byte - 1] = val;
	}
	else
	{
		tmp = (short int)(get_nbr(con, index, 2));
		val = get_nbr(con, get_index(proc->index, tmp), 4);
		proc->r[con->mem[get_index(index, 2)].byte - 1] = val;
	}
	if (val == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
