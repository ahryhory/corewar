/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:33:07 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/27 15:41:47 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static	void	s_cpy_proc(t_proc *proc, t_proc *new_proc)
{
	int		i;

	i = 0;
	while (++i < 16)
		new_proc->r[i] = (unsigned int)(proc->r[i]);
	new_proc->carry = proc->carry;
	new_proc->live = proc->live;
	new_proc->cycl = proc->cycl;
}

void			do_fork(t_con *con, int index, t_proc *proc)
{
	short int		nbr;
	t_proc	*new_proc;

	printf("COMMAND: fork\n");
	nbr = (short int)get_nbr(con, get_index(proc->index, 1), 2);
	vm_add_proces(con, get_index(index, nbr % IDX_MOD), proc->r[0]);
	new_proc = con->proc;
	s_cpy_proc(proc, new_proc);
}
