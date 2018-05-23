/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_give_codg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:03:43 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/23 19:49:12 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	s_helpa(t_proc *proc, int i)
{
	int		j;

	j = -1;
	while (++j != 3)
		if (g_optab[proc->mem[proc->index].byte - 1].args[i][j])
			return (1);
	return (0);
}

static void	s_add_cp(t_proc *proc, unsigned int *codg)
{
	int		n;
	int		i;

	n = (proc->mem)[proc->index].byte >= 9 &&
	proc->mem[proc->index].byte != 13 && proc->mem[proc->index].byte != 16 ?
	2 : 4;
	i = -1;
	proc->cp = 1;
	while (++i < 3)
	{
		if (!codg[i])
			continue;
		if (s_helpa(proc, i))
		{
			if (codg[i] == 1)
				proc->cp++;
			else
				proc->cp = codg[i] == 2 ? proc->cp + n : proc->cp + 2;
		}
	}
//	printf("proc->cp = %d\n", proc->cp);
}

int			vm_give_codg(t_proc *proc, unsigned int *codg)
{
	int		index;
	int		i;
	int		j;

	index = get_index(proc->index, 1);
	codg[0] = (proc->mem)[index].byte >> 6;
	codg[1] = (((proc->mem)[index].byte << 26) >> 30) & 3;
	codg[2] = (((proc->mem)[index].byte << 28) >> 30) & 3;
/*	printf("Codg logo: index = %d\n", index);
	printf("	codg[0] = %d\n", codg[0]);
	printf("	codg[1] = %d\n", codg[1]);
	printf("	codg[2] = %d\n", codg[2]);
*/	s_add_cp(proc, codg);
	i = 0;
	while (i < 3)
	{
		if (!codg[i] && (j = -1))
		{
			while (++j != 3)
				if (g_optab[proc->mem[proc->index].byte - 1].args[i][j])
					return (0);
			i++;
			continue;
		}
		if ((codg[i] &&
	g_optab[proc->mem[proc->index].byte - 1].args[i][codg[i] - 1]))
		{
			i++;
			continue;
		}
		return (0);
	}
	return (1);
}
