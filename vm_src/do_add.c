/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:31:58 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/17 19:55:53 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_add(t_con *con, int index, t_proc *proc)
{
	printf("COMMAND: add\n");
	proc->r[con->mem[get_index(index, 4)].byte] = proc->r[con->mem[get_index(index, 2)].byte] + proc->r[con->mem[get_index(index, 3)].byte];
	if (proc->r[con->mem[get_index(index, 4)].byte] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
