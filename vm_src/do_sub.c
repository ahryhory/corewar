/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:35:28 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/01 15:40:30 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_sub(t_con *con, int index, t_proc *proc)
{
	proc->r[con->mem[get_index(index, 4)].byte - 1] =
		proc->r[con->mem[get_index(index, 2)].byte - 1] -
		proc->r[con->mem[get_index(index, 3)].byte - 1];
	if (proc->r[con->mem[get_index(index, 4)].byte - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
