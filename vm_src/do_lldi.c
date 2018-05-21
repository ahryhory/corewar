/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:34:50 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/21 18:41:59 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_lldi(t_con *con, int index, unsigned int *n, t_proc *proc)
{	
	int		num_1;
	int		num_2;
	int		arg_1;
	int		res;
	int		step;

	printf("COMMAND: lldi\n");
	if (n[0] == 1)
	{
		num_1 = (short int)proc->r[con->mem[get_index(index, 2)].byte - 1];
		step = 1;
	}
	else
	{
		num_1 = (short int)get_nbr(con, get_index(index, 2), 2);
		step = 2;
	}
	if (n[1] == 1)
	{
		num_2 = (short int)proc->r[con->mem[get_index(index, 2 + step)].byte - 1];
		step++;
	}
	else
	{
		num_2 = (short int)get_nbr(con, get_index(index, 2 + step), 2);
		step += 2;
	}
	if (n[0] == 3)
		arg_1 = get_nbr(con, get_index(index, num_1), 4);
	else
		arg_1 = num_1;
	res = get_nbr(con, get_index(index, (num_1 + num_2)), 4);
	proc->r[con->mem[get_index(index, 2 + step)].byte - 1] = res;

}
