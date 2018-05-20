/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:35:34 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/20 13:51:51 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_xor(t_con *con, int index, unsigned int *n, t_proc *proc)
{
	int		num_1;
	int		num_2;
	int		step;

	printf("COMMAND: xor\n");
	if (n[0] == 1)
	{
		num_1 = proc->r[con->mem[get_index(index, 2)].byte];
		step = 1;
	}
	else if (n[0] == 2)
	{
		num_1 = get_nbr(con, get_index(index, 2), 4);
		step = 4;
	}
	else if (n[0] == 3)
	{
		num_1 = get_nbr(con, get_index(index, 2), 2);
		step = 2;
	}
	if (n[1] == 1)
	{
		num_2 = proc->r[con->mem[get_index(index, 2 + step)].byte];
	}
	else if (n[1] == 2)
	{
		num_2 = get_nbr(con, get_index(index, 2 + step), 4);
	}
	else if (n[1] == 3)
	{
		num_2 = get_nbr(con, get_index(index, 2 + step), 2);
	}
	proc->r[con->mem[get_index(index, 4)].byte] = num_1 ^ num_2;
}
