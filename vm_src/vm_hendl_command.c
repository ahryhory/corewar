/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_hendl_comand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:11:39 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/16 16:33:11 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	s_hendl_nocodg(t_proc *proc, t_con *con)
{
	if ((proc->mem)[proc->index].byte == 1)
	{
		do_live(con, proc->index, proc);
		proc->cp = 4;
	}
	if ((proc->mem)[proc->index].byte == 9)
	{
		do_zjmp(con, proc->index, proc);
		proc->cp = 2;
	}
	if ((proc->mem)[proc->index].byte == 12)
	{
		do_fork(con, proc->index, proc);
		proc->cp = 2;
	}
	if ((proc->mem)[proc->index].byte == 15)
	{
		do_lfork(con, proc->index, proc);
		proc->cp = 2;
	}
}

static void	s_helpa_codg(t_proc *proc, t_con *con, int *codg)
{
	if ((proc->mem)[proc->index].byte == 11)
		do_sti(con, proc->index, codg, proc);
	if ((proc->mem)[proc->index].byte == 13)
		do_lld(con, proc->index, codg, proc);
	if ((proc->mem)[proc->index].byte == 14)
		do_lldi(con, proc->index, codg, proc);
	if ((proc->mem)[proc->index].byte == 16)
		do_aff(con, proc->index, proc);
}

void		vm_hendl_command(t_proc *proc, t_con *con)
{
	int		codg[3];

	if (g_optab[(proc->mem)[proc->index].byte].cod_octal &&
			vm_give_codg(proc, codg))
	{
		if ((proc->mem)[proc->index].byte == 2)
			do_ld(con, proc->index, codg, proc);
		if ((proc->mem)[proc->index].byte == 3)
			do_st(con, proc->index, codg, proc);
		if ((proc->mem)[proc->index].byte == 4)
			do_add(con, proc->index, proc);
		if ((proc->mem)[proc->index].byte == 5)
			do_sub(con, proc->index, proc);
		if ((proc->mem)[proc->index].byte == 6)
			do_and(con, proc->index, codg, proc);
		if ((proc->mem)[proc->index].byte == 7)
			do_or(con, proc->index, codg, proc);
		if ((proc->mem)[proc->index].byte == 8)
			do_xor(con, proc->index, codg, proc);
		if ((proc->mem)[proc->index].byte == 10)
			do_ldi(con, proc->index, codg, proc);
		s_helpa_codg(proc, con, codg);
	}
	else
		s_hendl_nocodg(proc, con);
}
