/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:32:28 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/15 21:15:12 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		do_ld(t_con *con, int index, int *n, t_proc *proc)
{
	index = get_index(index, 2); // because this command has codage
	if (n[0] == 2)
		proc->r[con->mem[get_index(index, 3)].byte] = get_nbr(con, index, 2);
	else
	{
		proc->r[(con->mem[get_index(index, 5)]).byte] = get_nbr(con, index, 4);
	}
}
