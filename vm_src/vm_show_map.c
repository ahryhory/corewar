/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 19:35:14 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/21 20:18:22 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_show_map(t_con con)
{
	t_mem	*mem;
	int		i;
	int		j;

	mem = con.mem;
	i = 0;
	j = -1;
	while (i < MEM_SIZE)
	{
		printf("%2.2x ", mem[i++].byte);
		if (i % 64 == 0 && (++j || !j))
		{
			if (j == 0)
				printf("%20s %d", "cycl:          ", con.cycl);
			if (j == 2)
				printf("%20s %d", "cycl_to_day:   ", con.cycl_to_die);
//			if (j == 4)
//				printf("%4c cycl: %d", ' ', con->cycl);
//			else if (j
			printf("\n");
		}
	}
	printf("%d\n", i);
}
