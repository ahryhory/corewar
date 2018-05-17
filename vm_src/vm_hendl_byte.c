/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_hendl_byte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:09:50 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/17 21:14:21 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Хочешь увидеть магию? 
** Раскоменть оба "RAZKOMENT", а затем закоренть "RAZKOMENT (2)". 
*/
static void	s_init_proc(t_proc *proc)
{
	if ((proc->mem)[proc->index].byte >= 1 &&
			(proc->mem)[proc->index].byte <= 16)
	{
		proc->work = 1;
		proc->cycl = g_optab[(proc->mem)[proc->index].byte - 1].cycles;
	//	printf("!!!!!!!!!!!!!!!minus cycl: %d\n",  proc->cycl); //RAZKOMENT (1)
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
//	printf("CYCL in hendl_byte %d\n", con->cycl);    //RAZKOMENT (2)
	if (!proc->work)
		s_init_proc(proc);
	if (proc->cycl > 0)
		proc->cycl--;
	if (!proc->cycl && proc->work)
	{
		vm_hendl_command(proc, con);
		proc->work = 0;
	}
	if (!proc->cycl && proc->cp)
	{
		printf("do cp-- %d\n", proc->cp);
		while (--(proc->cp) > 0)
			proc->index = proc->index >= MEM_SIZE ? 0 : proc->index + 1;
		proc->index = proc->index >= MEM_SIZE ? 0 : proc->index + 1;
		proc->index = proc->index >= MEM_SIZE ? 0 : proc->index + 1;
	}
	else if (!proc->cycl)
	{
		proc->index = proc->index >= MEM_SIZE ? 0 : proc->index + 1;
	}
	proc->cycl_live--;
}
