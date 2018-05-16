/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_hendl_byte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:09:50 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/16 16:35:42 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	s_init_proc(t_proc *proc)
{
	if ((proc->mem)[proc->index].byte >= 1 &&
			(proc->mem)[proc->index].byte <= 16)
	{
		proc->work = 1;
		proc->cycl = g_optab[(proc->mem)[proc->index].byte].cycles;
	}
	else
	{
		proc->work = 0;
		proc->index = proc->index >= MEM_SIZE ? 0 : proc->index + 1;
		proc->cycl = 0;
	}
}

void		vm_hendl_byte(t_proc *proc, t_con *con)
{
	if (!proc->work)
		s_init_proc(proc);
	if (!proc->cycl && proc->work)
		vm_hendl_command(proc, con);
	if (!proc->cycl && proc->cp)
		while ((proc->cp)--)
			proc->index = proc->index >= MEM_SIZE ? 0 : proc->index + 1;
	proc->cycl_live--;
}
