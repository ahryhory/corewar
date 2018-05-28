/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_hendl_proc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:04:25 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/27 16:08:53 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_hendl_proc(t_con *con)
{
	int		i;
	t_proc	*proc;

	if (!(proc = 0) && con)
		proc = con->proc;
	i = 0;
	while (proc)
	{
		if (proc && !proc->live)
		{
			printf("Proces died\n");
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
