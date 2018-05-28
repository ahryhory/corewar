/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 19:35:14 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/27 22:05:13 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	s_print_reg(t_proc *proc, int j)
{
	int		i;

	i = -1;
	if (j == -2)
		while (proc && ++i <= 8)
		{
			printf("%10d", (char)proc->mem[proc->index].chemp->nbr[3]);
			proc = proc->next;
		}
	else if (j == -1)
	{
		printf("     index:");
		while (proc && ++i <= 8)
		{
			printf(" %-10d", proc->index);
			proc = proc->next;
		}
	}
	else
	{
		printf("     r[%2d%-3s", j + 1, "]");
		while (proc && ++i <= 8)
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
	printf("0x%.4x : ", i);
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
				printf("%20s %d", "Proces:", vm_count_proc(con.proc));
			if (j > 3 && j < REG_NUMBER + 6)
				s_print_reg(con.proc, j - 6);
//			if (j == 4)
//				printf("%4c cycl: %d", ' ', con->cycl);
//			else if (j
			printf("\n");
			if (i < MEM_SIZE)
				printf("%#.4x : ", i);
		}
	}
}
