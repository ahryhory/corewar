/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 15:58:24 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/13 19:35:24 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdio.h>

void	general_cycle(t_con *con, int *start)
{
	while (con->cycl_to_die > 0 && con->proc)
	{
		vm_check_proc(con);
		if (s_check_cycl(con))
		{
			if ((con->cycl_to_die -= CYCLE_DELTA) <= 0 ||
					!vm_count_proc(con->proc))
				break ;
			con->m_check = 0;
			s_null_chemp(con);
		}
		if (g_flag.dump != -1 && con->cycl == g_flag.dump && !g_flag.v)
			write_dump(con->mem);
		if (g_flag.v)
			start_ncurs(start, con);
		vm_hendl_proc(con);
		con->cycl++;
		con->cycl_die_per++;
	}
}
