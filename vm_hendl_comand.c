/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_hendl_comand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:11:39 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/15 15:44:13 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_hendl_command(t_proc *proc)
{
	if ((proc->mem)[proc->index]->byte == 1)
		do_live(proc->mem, proc->index, proc);
	if ((proc->
}
