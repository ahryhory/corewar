/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:32:37 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/13 16:46:25 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	s_add_to_mem(t_con *con, unsigned int value, int index,
		t_chemp *chemp)
{
	con->mem[index].chemp = chemp;
	con->mem[index].byte = (value >> 24) & 255;
	con->mem[index].light = con->cycl;
	index = get_index(index, 1);
	con->mem[index].chemp = chemp;
	con->mem[index].byte = (value >> 16) & 255;
	con->mem[index].light = con->cycl;
	index = get_index(index, 1);
	con->mem[index].chemp = chemp;
	con->mem[index].byte = (value >> 8) & 255;
	con->mem[index].light = con->cycl;
	index = get_index(index, 1);
	con->mem[index].chemp = chemp;
	con->mem[index].byte = value & 255;
	con->mem[index].light = con->cycl;
}

void		do_st(t_con *con, int index, unsigned int *n, t_proc *proc)
{
	int				indx;
	unsigned int	tmp;
	t_chemp			*chemp;

	chemp = proc->chemp;
	index = get_index(index, 2);
	if (n[1] == 3)
	{
		indx = get_index(proc->index,
				(short int)(get_nbr(con, get_index(index, 1), 2)) % IDX_MOD);
		tmp = proc->r[con->mem[index].byte - 1];
		s_add_to_mem(con, tmp, indx, chemp);
	}
	else
		proc->r[con->mem[get_index(index, 1)].byte - 1] =
			proc->r[con->mem[index].byte - 1];
}
