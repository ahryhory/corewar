/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:32:37 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/17 19:57:58 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_st(t_con *con, int index, int *n, t_proc *proc)
{
	int		coord;

	printf("COMMAND: st\n");
	index = get_index(index, 2);
	if (n[0] == 1)
		con->mem[get_index(index, get_nbr(con, get_index(index, 1), 2) % IDX_MOD)].byte = proc->r[con->mem[index].byte];
	else
		proc->r[get_nbr(con, get_index(index, 1), 1)] = proc->r[con->mem[index].byte];
}
