/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_hendl_byte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:09:50 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/15 14:33:34 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_hendl_byte(t_proc *proc)
{
	if (!proc->worc)
		vm_init_proc(proc);
	if (!cycl)
		vm_hendl_comand(proc);
	cycl_live--;
}
