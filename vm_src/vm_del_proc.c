/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_del_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:00:56 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/26 21:50:31 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_del_proc(t_con **con, int i)
{
	t_proc	*proc;
	t_proc	*s_proc;

	printf("proc: %d\n", vm_count_proc((*con)->proc));
	if (!(proc = (*con)->proc))
		return ;
	if (!i)
	{
		(*con)->proc = (*con)->proc->next;
		proc->mem = 0;
		free(proc);
		proc = 0;
		return ;
	}
	while (i-- && (s_proc = proc))
		proc = proc->next;
	s_proc->next = proc->next;
	proc->mem = 0;
	free(proc);
	proc = 0;
}
