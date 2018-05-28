/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_del_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:00:56 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/27 15:36:06 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_del_proc(t_con **con, int i)
{
	t_proc	*proc;
	t_proc	*s_proc;

//	printf("proc: %d\n", vm_count_proc((*con)->proc));
	if (!(proc = (*con)->proc))
		return ;
	if (!i)
	{
		(*con)->proc = (*con)->proc->next;
		free(proc->r);
		free(proc);
		proc = 0;
		return ;
	}
	while (i-- && (s_proc = proc))
		proc = proc->next;
	s_proc->next = proc->next;
	free(proc->r);
	free(proc);
	proc = 0;
}
