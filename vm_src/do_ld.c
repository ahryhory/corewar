/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:32:28 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/15 14:33:17 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	get_nbr(t_con *con, int index)
{
	int		n1;
	int		n2;
	int		n3;
	int		n4;

	n1 = con->mem[index].byte;
	n2 = con->mem[get_index(index, 1)].byte;
	n3 = con->mem[get_index(index, 2)].byte;
	n4 = con->mem[get_index(index, 3)].byte;
	n1 = n1 << 24;
	n2 = n2 << 16;
	n3 = n3 << 8;
	return (n1 + n2 + n3 + n4);
}

void		do_ld(t_con *con, int index, int *n, t_proc *proc)
{
	index = get_index(index, 2); // because this command has codage
	if (n[0] == 2)
		proc->r[con->mem[get_index(index, 4)].byte] = get_nbr(con, index);
	else
	{

	}
	// if (proc->index == MEM_SIZE)
	// 	proc->index = 0;
	// else
	// 	proc->index++;
}
