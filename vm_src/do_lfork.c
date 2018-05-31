/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:33:32 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/31 20:07:26 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static	void	s_cpy_proc(t_proc *proc, t_proc *new_proc)
{
	int		i;

	i = 0;
	while (++i < 16)
		new_proc->r[i] = proc->r[i];
	new_proc->carry = proc->carry;
	new_proc->live = proc->live;
	new_proc->cycl = proc->cycl;
	new_proc->chemp = proc->chemp;
}

void			do_lfork(t_con *con, int index, t_proc *proc)
{
	int		nbr;
	t_proc	*new_proc;

	nbr = (short int)get_nbr(con, get_index(proc->index, 1), 2);
	vm_add_proces(con, get_index(index, nbr), proc->r[0]);
	new_proc = con->proc;
	s_cpy_proc(proc, new_proc);
}
