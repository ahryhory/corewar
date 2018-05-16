/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_del_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:00:56 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/16 16:36:54 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_del_proc(t_proc **b_proc, int i)
{
	t_proc	*proc;
	t_proc	*s_proc;

	if (!b_proc || !(proc = *b_proc))
		return ;
	if (!i)
	{
		*b_proc = (*b_proc)->next;
		free(proc);
		return ;
	}
	while (i && (s_proc = proc))
		proc = proc->next;
	s_proc->next = proc->next;
	free(proc);
}
