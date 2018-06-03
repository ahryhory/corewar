/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:31:58 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/31 20:03:24 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_add(t_con *con, int index, t_proc *proc)
{
	proc->r[con->mem[get_index(index, 4)].byte - 1] =
		(unsigned int)(proc->r[con->mem[get_index(index, 2)].byte - 1] +
		proc->r[con->mem[get_index(index, 3)].byte - 1]);
	if (proc->r[con->mem[get_index(index, 4)].byte - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
