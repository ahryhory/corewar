/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_hendl_rule.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:09:30 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/16 18:44:54 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_hendl_proc(t_con *con)
{
	int		i;
	t_proc	*proc;

	proc = con->proc;
	i = 0;
	while (proc)
	{
		if (proc && !proc->cycl_live)
		{
			printf("del proc\n");
			proc = proc->next;
			vm_del_proc(&con, i);
			continue;
		}
		i++;
		vm_hendl_byte(proc, con);
		proc = proc->next;
	}
	return (i);
}
