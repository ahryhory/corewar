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

void	do_ld(t_con *con, int index, int *n, t_proc *proc)
{
	index = get_index(index, 1); // because this command has codage
	// if (n[0] == 2)
	// {
	// 	proc->r[con->map[get_index(index, 1)]]
	// }
	// else
	// {

	// }
}
