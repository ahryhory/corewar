/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_hendl_rule.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:09:30 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/15 19:14:33 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_hendl_proc(t_con *con)
{
	int		i;
	t_proc	*proc;
	t_proc	*b_proc;

	proc = con->proc;
	i = 0;
	b_proc = proc;
	while (proc)
	{
		if (!proc->cycl_live)
		{
			proc = proc->next;
			vm_del_proc(&b_proc, i);
			continue;
		}
		i++;
		vm_hendl_byte(proc, con);
		proc = proc->next;
	}
	return (i);
}
