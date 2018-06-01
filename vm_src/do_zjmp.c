/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:35:41 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/01 15:40:44 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_zjmp(t_con *con, int index, t_proc *proc)
{
	int		coord;

	if (proc->carry == 0)
		return ;
	coord = ((short int)(get_nbr(con, get_index(index, 1), 2))) % IDX_MOD;
	proc->cp = -1;
	proc->index = get_index(index, coord);
}
