/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:40:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/16 16:49:07 by iseletsk         ###   ########.fr       */
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

static void		s_init_con(t_con *con)
{
	con->cycl_to_day = CYCLE_TO_DIE;
	con->cycl = 0;
	con->cycl_day_per = 0;
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
	s_init_con(&con);
	i = 0;
	while (con.cycl_to_day > 0)
	{
		i++;
		if (con.cycl_day_per == con.cycl_to_day)
		{
			con.cycl_to_day -= CYCLE_DELTA;
			con.cycl_day_per = 0;
		}
		vm_hendl_proc(&con);
		con.cycl++;
		con.cycl_day_per++;
	}
	i = 0;
	while (i < MEM_SIZE)
	{
		printf("%d ", con.mem[i].byte);
		i++;
	}
	return (0);
}
