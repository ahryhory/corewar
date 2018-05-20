/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:40:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/19 19:39:14 by iseletsk         ###   ########.fr       */
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

static void		s_init_con(t_con *con, t_chemp **chemp, int nbr)
{
	*chemp = vm_add_chemp(nbr);
	con->cycl_to_die = CYCLE_TO_DIE;
	con->cycl = 0;
	con->m_check = 0;
	con->cycl_die_per = 0;
	con->mem = 0;
	con->chemp = *chemp;
	con->proc = 0;
}

static void		s_null_chemp(t_con *con)
{
	t_chemp	*chemp;

	chemp = con->chemp;
	while (chemp)
	{
		chemp->live_icp = 0;
		chemp = chemp->next;
	}
}

static int		s_check_cycl(t_con *con)
{
	t_chemp	*chemp;
	int		i;

	chemp = con->chemp;
	printf("chemp live: %d\n", chemp->live_icp);
	if (con->cycl_die_per >= con->cycl_to_die)
	{
		con->m_check++;
		con->cycl_die_per = 0;
		while (chemp)
		{
			printf("i\n");
			if (chemp->live_icp >= 21)
			{
				printf("\nlive_icp >= 21\n");
				//read(0, &i, 1);
				return (1);
			}
			chemp = chemp->next;
		}
		if (con->m_check >= 10)
		{
			printf("\nm_check >= 10\n");
		//	read(0, &i, 1);
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
	int			i;
	t_chemp		*chemp;

	init_optab();
	if (ac == 1)
		exit(1);
	s_init_con(&con, &chemp, ac - 1); ///// nbr chemp!
	con.mem = allocate_memory();
	add_champions(&con, ac, av, chemp);

	while (con.cycl_to_die > 0 && con.proc)
	{
		printf("cycl: %d, %d\n", con.cycl, con.cycl_to_die);
		if (s_check_cycl(&con))
		{
			if ((con.cycl_to_die -= CYCLE_DELTA) <= 0)
				break ;
			con.m_check = 0;
			s_null_chemp(&con);
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
