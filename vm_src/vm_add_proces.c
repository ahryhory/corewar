/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_add_proces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:32:34 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/26 22:02:54 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		s_init_r(unsigned int *r, int nbr)
{
	int		i;

	i = 1;
	r[0] = (unsigned int)nbr;
	while (i < 16)
		r[i++] = 0;
}

static t_proc	*s_init_proc(t_con *con, int index, int nbr)
{
	t_proc	*proc;

	printf("proc: %d\n", vm_count_proc(con->proc));
	proc = malloc(sizeof(t_proc));
	printf("1\n");
	s_init_r(proc->r, nbr);
	proc->cp = 0;
	proc->carry = 0;
	proc->do_byte = 0;
	proc->cycl = 0;
	proc->live = 1;
	proc->index = index;
	proc->work = 0;
	proc->mem = con->mem;
	proc->next = 0;
	return (proc);
}

void	vm_add_proces(t_con *con, int index, int nbr)
{
	t_proc	*proc;

	proc = con->proc;
	con->proc = s_init_proc(con, index, nbr);
	con->proc->next = proc;
	/*
	if (!proc)
	{
		con->proc = s_init_proc(con, index, nbr);
		return ;
	}
	while (proc->next)
		proc = proc->next;
	proc->next = s_init_proc(con, index, nbr);
	*/
}

