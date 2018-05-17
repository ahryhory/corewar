/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_give_codg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:03:43 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/16 19:59:03 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	s_add_cp(t_proc *proc, int *codg)
{
	int		n;
	int		i;

	n = (proc->mem)[proc->index].byte >= 9 &&
	proc->mem[proc->index].byte != 13 && proc->mem[proc->index].byte != 16 ?
	2 : 4;
	printf("ALAL!!!!%d\n", n);
	i = -1;
	proc->cp = 1;
	while (++i < 3)
	{
		if (!codg[i])
			continue;
		if (codg[i] == 1)
			proc->cp++;
		else
			proc->cp = codg[i] == 2 ? proc->cp + n : proc->cp + 2;
	}
}

int			vm_give_codg(t_proc *proc, int *codg)
{
	int		index;
	int		*arg;
	int		i;

	arg = (int *)g_optab[proc->mem[proc->index].byte].args;
	index = proc->index >= MEM_SIZE ? 0 : proc->index + 1;
	codg[0] = (proc->mem)[index].byte >> 6;
	codg[1] = ((proc->mem)[index].byte << 26) >> 30;
	codg[2] = ((proc->mem)[index].byte << 28) >> 30;
	s_add_cp(proc, codg);
	i = 0;
	while (i < 3 && arg)
	{
		if ((arg[codg[i] - 1] && !codg[i]) || (!arg[codg[i] - 1] && codg[i]))
			return (0);
		i++;
	}
	return (1);
}
