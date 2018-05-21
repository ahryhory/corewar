/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:35:20 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/21 23:09:49 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	s_add_to_mem(t_con *con, unsigned int value, int index)
{
	con->mem[index++].byte = (value >> 24) & 255;
	con->mem[index++].byte = (value >> 16) & 255;
	con->mem[index++].byte = (value >> 8) & 255;
	con->mem[index++].byte = value & 255;
}

void	do_sti(t_con *con, int index, unsigned int *n, t_proc *proc)
{
	int		arg_1;
	int		arg_2;
	int		value;
	int		ndx;
	int		step;

	printf("COMMAND: sti\n");
	ndx = 0;
	if (n[1] == 1 && (step = 2))
		arg_1 = (short int)proc->r[con->mem[get_index(index, 3)].byte - 1];
	else if ((step = 3))
		arg_1 = (short int)get_nbr(con, get_index(index, 3), 2);
	if (n[1] == 3 && (step = 3))
		arg_1 = (short int)get_nbr(con, get_index(index, arg_1 % IDX_MOD), 4);
	if (n[2] == 1)
		arg_2 = (short int)proc->r[con->mem[get_index(index, step)].byte - 1];
	else if (n[2] == 2)
		arg_2 = (short int)get_nbr(con, get_index(index, step), 2);
	value = (unsigned int)proc->r[con->mem[get_index(index, 2)].byte - 1];
	s_add_to_mem(con, value, index + (arg_1 + arg_2) % IDX_MOD);
}
