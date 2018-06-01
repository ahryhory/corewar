/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_add_proces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:32:34 by iseletsk          #+#    #+#             */
/*   Updated: 2018/06/01 20:11:56 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static unsigned int	*s_init_r(int nbr)
{
	int				i;
	unsigned int	*r;

	r = (unsigned int *)malloc(sizeof(unsigned int) * (REG_NUMBER));
	i = 1;
	r[0] = (unsigned int)nbr;
	while (i < 16)
		r[i++] = 0;
	return (r);
}

static t_proc		*s_init_proc(t_con *con, int index, int nbr)
{
	t_proc	*proc;

	proc = malloc(sizeof(t_proc));
	proc->r = s_init_r(nbr);
	proc->cp = 0;
	proc->carry = 0;
	proc->do_byte = 0;
	proc->cycl = 0;
	proc->live = 1;
	proc->index = index;
	proc->work = 0;
	proc->mem = con->mem;
	proc->next = 0;
	proc->chemp = con->mem[index].chemp;
	proc->cycl_create = con->cycl;
	proc->index_create = index;
	return (proc);
}

void				vm_add_proces(t_con *con, int index, int nbr)
{
	t_proc	*proc;

	proc = con->proc;
	con->proc = s_init_proc(con, index, nbr);
	con->proc->next = proc;
}
