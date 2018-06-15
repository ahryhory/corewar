/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:30:20 by iseletsk          #+#    #+#             */
/*   Updated: 2018/06/12 14:20:15 by iseletsk         ###   ########.fr       */
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

static void		s_init_con(t_con *con, t_chemp **chemp)
{
	*chemp = vm_add_chemp();
	con->cycl_to_die = CYCLE_TO_DIE;
	con->cycl = 0;
	con->m_check = 0;
	con->cycl_die_per = 0;
	con->mem = 0;
	con->chemp = *chemp;
	con->proc = 0;
	con->live = 0;
	con->winer = 0;
}

void			s_null_chemp(t_con *con)
{
	t_chemp	*chemp;

	con->live = 0;
	chemp = con->chemp;
	while (chemp)
	{
		chemp->live_icp = 0;
		chemp = chemp->next;
	}
}

int				s_check_cycl(t_con *con)
{
	t_chemp	*chemp;

	chemp = con->chemp;
	if (!vm_count_proc(con->proc))
		return (1);
	if (con->cycl_die_per >= con->cycl_to_die)
	{
		con->m_check++;
		con->cycl_die_per = 0;
		if (con->live >= 21)
			return (1);
		if (con->m_check >= 10)
		{
			con->m_check = 0;
			return (1);
		}
		s_null_chemp(con);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_con		con;
	t_chemp		*chemp;
	int			start;

	vm_init_flag(ac, av);
	init_optab();
	start = 0;
	con.step = 0;
	if (ac == 1)
		usage_vm();
	s_init_con(&con, &chemp);
	con.mem = allocate_memory(chemp);
	add_champions(&con, av, chemp->next);
	vm_salution(con, av);
	if_v(&con);
	general_cycle(&con, &start);
	system("./end_proc");
	vm_give_winer(&con);
	return (0);
}
