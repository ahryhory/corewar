/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:35:41 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/17 19:58:55 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_zjmp(t_con *con, int index, t_proc *proc)
{
	int		coord;

	printf("COMMAND: zjmp, carry: %d\n", proc->carry);
	if (proc->carry == 0)
		return ;
	coord = get_nbr(con, get_index(index, 1), 2) % IDX_MOD;
	proc->index = get_index(index, coord);
}
