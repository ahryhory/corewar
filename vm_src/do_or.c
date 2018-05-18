/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:35:07 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/17 19:57:41 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_or(t_con *con, int index, int *n, t_proc *proc)
{	
	printf("COMMAND: or\n");
	con->mem[get_index(index, 4)].byte = con->mem[get_index(index, 2)].byte | con->mem[get_index(index, 3)].byte;
	if (con->mem[get_index(index, 4)].byte == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
