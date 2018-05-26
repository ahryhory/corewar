/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 19:35:14 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/26 20:27:38 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	s_print_reg(t_proc *proc, int j)
{
	int		i;

	i = -1;
	if (j == -1)
		while (proc && ++i <= 4)
		{
			printf("%9d", (char)proc->mem[proc->index].chemp->nbr[3]);
			proc = proc->next;
		}
	else
	{
		printf("r[%2d%-3s", j + 1, "]");
		while (proc && ++i <= 4)
		{
			printf("%-10.8x", proc->r[j]);
			proc = proc->next;
		}
	}
}

void	vm_show_map(t_con con)
{
	t_mem	*mem;
	int		i;
	int		j;

	mem = con.mem;
	i = 0;
	j = -1;
	while (i < MEM_SIZE)
	{
		printf("%2.2x ", mem[i++].byte);
		if (i % 64 == 0 && (++j || !j))
		{
			if (j == 0)
				printf("%20s %d", "cycl:          ", con.cycl);
			if (j == 2)
				printf("%20s %d", "cycl_to_day:   ", con.cycl_to_die);
			if (j == 3)
				printf("%20s", "Proces:");
			if (j > 3 && j < REG_NUMBER + 5)
				s_print_reg(con.proc, j - 5);
			printf("\n");
		}
	}
}
