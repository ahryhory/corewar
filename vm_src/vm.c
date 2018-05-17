/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:40:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/17 17:51:22 by iseletsk         ###   ########.fr       */
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
	con->cycl_to_die = CYCLE_TO_DIE;
	con->cycl = 0;
	con->cycl_die_per = 0;
	con->mem = 0;
	con->chemp = 0;
	con->proc = 0;
}

int				main(int ac, char **av)
{
	t_con		con;
	int			i;

	init_optab();
	if (ac == 1)
		exit(1);
	s_init_con(&con);
	con.mem = allocate_memory();
	add_champions(&con, ac, av);
	while (con.cycl_to_die > 0 && con.proc)
	{
		printf("cycl: %d\n", con.cycl);
		if (con.cycl_die_per == con.cycl_to_die) //добавить условия на 21 жизнь
		{
			con.cycl_to_die -= CYCLE_DELTA;
			con.cycl_die_per = 0;
		}
		vm_hendl_proc(&con);
		con.cycl++;
		con.cycl_die_per++;
	}
	i = 0;
	while (i < MEM_SIZE)
	{
		printf("%d ", con.mem[i].byte);
		i++;
	}
	return (0);
}
