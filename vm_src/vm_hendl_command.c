/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_hendl_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:57:53 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/27 21:46:17 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	s_hendl_nocodg(t_proc *proc, t_con *con)
{
//printf("do byte: %d, index: %d, cycle: %d\n", (proc->mem)[proc->index].byte, proc->index, con->cycl);

	if (proc->do_byte == 1)
	{
		do_live(con, proc->index, proc);
		proc->cp = 4;
	}
	if (proc->do_byte == 9)
	{
		proc->cp = 2;
		do_zjmp(con, proc->index, proc);
	}
	if (proc->do_byte == 12)
	{
		do_fork(con, proc->index, proc);
		proc->cp = 2;
	}
	if (proc->do_byte == 15)
	{
		do_lfork(con, proc->index, proc);
		proc->cp = 2;
	}
	if (con->dump < con->cycl)
	{
//		vm_show_map(*con);
//		read(0, 0, 1);
	}
}

static void	s_helpa_codg(t_proc *proc, t_con *con, unsigned int *codg)
{
	if (proc->do_byte == 11)
		do_sti(con, proc->index, codg, proc);
	if (proc->do_byte == 13)
		do_lld(con, proc->index, codg, proc);
	if (proc->do_byte == 14)
		do_lldi(con, proc->index, codg, proc);
	if (proc->do_byte == 16)
		do_aff(con, proc->index, proc);
	if (con->dump < con->cycl)
	{
//		vm_show_map(*con);
//		read(0, 0, 1);
	}
}

void		vm_hendl_command(t_proc *proc, t_con *con)
{
	unsigned int	codg[3];
	int				i;

	i = 0;
	if (g_optab[proc->do_byte - 1].cod_octal &&
			vm_give_codg(proc, codg))
	{
	////////
		i = 1;
//printf("do byte: %d, index: %d, cycle: %d\n", (proc->mem)[proc->index].byte, proc->index, con->cycl);

	//////
		if (proc->do_byte == 2)
			do_ld(con, proc->index, codg, proc);
		if (proc->do_byte == 3)
			do_st(con, proc->index, codg, proc);
		if (proc->do_byte == 4)
			do_add(con, proc->index, proc);
		if (proc->do_byte == 5)
			do_sub(con, proc->index, proc);
		if (proc->do_byte == 6)
			do_and(con, proc->index, codg, proc);
		if (proc->do_byte == 7)
			do_or(con, proc->index, codg, proc);
		if (proc->do_byte == 8)
			do_xor(con, proc->index, codg, proc);
		if (proc->do_byte == 10)
			do_ldi(con, proc->index, codg, proc);
		s_helpa_codg(proc, con, codg);
	}
	else
		s_hendl_nocodg(proc, con);
}
