/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_proc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:47:59 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/30 18:51:24 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_check_proc(t_con *con)
{
	t_proc	*proc;
	int		i;

	i = 0;
	if (!(proc = 0) && con)
		proc = con->proc;
	while (proc)
	{
		if (proc && !proc->live)
		{
			proc = proc->next;
			vm_del_proc(&con, i);
			continue;
		}
		i++;
		proc = proc->next;
	}
}
