/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:40:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/16 15:57:26 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		init_optab(void)
{
	init_name();
	init_args_number();
	init_args();
	init_opcode();
	init_cycles();
	init_description();
	init_carry();
	init_cod_octal();
	init_lable_size();
}

int				main(int ac, char **av)
{
	t_con		con;
	int			i;

	init_optab();
	if (ac == 1)
		exit(1);
	con.mem = allocate_memory();
	add_champions(&con, ac, av);
	while (con.cycle_to_day)
	{
		if (con.cycle_day_per == con.cycle_to_day)
		{
			con.cycle_to_day -= CYCLE_DELTA;
			con.cycle_day_per = 0;
		}
		vm_hendl_proc(&con);
		con.cycl++;
		con.cycle_dat_per++;
	}
	// i = 0;
	// while (i < MEM_SIZE)
	// {
	// 	printf("%d ", con->mem[i].byte);
	// 	i++;
	// }
	return (0);
}
