/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:34:50 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/23 19:48:34 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_lldi(t_con *con, int index, unsigned int *n, t_proc *proc)
{
	unsigned int		arg_1;
	unsigned int		arg_2;
	int		step;
	int		step2;

	printf("COMMAND: lldi\n");
	if (n[0] == 1 && (step = 1))
		arg_1 = proc->r[con->mem[get_index(index, 2)].byte - 1];
	else if ((step = 2))
		arg_1 = (short int)get_nbr(con, get_index(index, 2), 2);
	if (n[0] == 3)
		arg_1 = (short int)get_nbr(con, get_index(index, arg_1 % IDX_MOD), 4);
	if (n[1] == 1 && (step2 = 1))
		arg_2 = (short int)proc->r[con->mem[get_index(index, 2 + step)].byte
			- 1];
	else if (n[1] == 2 && (step2 = 2))
		arg_2 = (short int)get_nbr(con, get_index(index, step + 2), 2);
	proc->r[con->mem[get_index(index, 2 + step + step2)].byte - 1] =
	get_nbr(con, get_index(index, get_index(index,
					(short int)(arg_1 + arg_2))), 4);
	if (!proc->r[con->mem[get_index(index, 2 + step + step2)].byte - 1])
		proc->carry = 1;
	else
		proc->carry = 0;
}
