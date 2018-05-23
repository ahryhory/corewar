/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:35:20 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/23 19:53:59 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	s_add_to_mem(t_con *con, unsigned int value, int index,
		t_chemp *chemp)
{

	con->mem[index].chemp = chemp;
	con->mem[index].byte = (value >> 24) & 255;
	index = get_index(index, 1);
	con->mem[index].chemp = chemp;
	con->mem[index].byte = (value >> 16) & 255;
	index = get_index(index, 1);
	con->mem[index].chemp = chemp;
	con->mem[index].byte = (value >> 8) & 255;
	index = get_index(index, 1);
	con->mem[index].chemp = chemp;
	con->mem[index].byte = value & 255;
}

void	do_sti(t_con *con, int index, unsigned int *n, t_proc *proc)
{
	int		arg_1;
	int		arg_2;
	int		value;
	t_chemp	*chemp;
	int		step;

	chemp = con->mem[index].chemp;
	printf("COMMAND: sti\n");
	value = (unsigned int)proc->r[con->mem[get_index(index, 2)].byte - 1];
	if (n[1] == 1 && (step = 1))
		arg_1 = (short int)proc->r[con->mem[get_index(index, 3)].byte - 1];
	else if ((step = 2))
		arg_1 = (short int)get_nbr(con, get_index(index, 3), 2);
	if (n[1] == 3)
		arg_1 = get_nbr(con, get_index(index, arg_1 % IDX_MOD), 4);
	if (n[2] == 1)
		arg_2 = (short int)proc->r[con->mem[get_index(index, 3 + step)].byte
			- 1];
	else if (n[2] == 2)
		arg_2 = (short int)get_nbr(con, get_index(index, step + 3), 2);
	s_add_to_mem(con, value, get_index(index, (short int)((arg_1 + arg_2)
					% IDX_MOD)), chemp);
}
