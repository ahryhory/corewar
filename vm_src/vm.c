/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:40:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/29 14:38:21 by iseletsk         ###   ########.fr       */
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

static void		s_init_con(t_con *con, t_chemp **chemp, int nbr, char **av)
{
	*chemp = vm_add_chemp(nbr);
	con->cycl_to_die = CYCLE_TO_DIE;
	con->cycl = 0;
	con->m_check = 0;
	con->dump = ft_strcmp(av[1], "-d") == 0 ? ft_atoi(av[2]) : 0;
	con->cycl_die_per = 0;
	con->mem = 0;
	con->chemp = *chemp;
	con->proc = 0;
	con->live = 0;
}

static void		s_null_chemp(t_con *con)
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

static int		s_check_cycl(t_con *con)
{
	t_chemp	*chemp;

	chemp = con->chemp;
	if (con->cycl_die_per >= con->cycl_to_die)
	{
		con->m_check++;
		con->cycl_die_per = 0;
		if (con->live >= 21)
		{
			//printf("live >= 21\n");
			return (1);
		}
		if (con->m_check >= 10)
		{
			//printf("\nm_check >= 10\n");
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
	int			k;
	int			step;
	int		c;

	init_optab();
	k = 1;
	step = 1;
	if (ac == 1)
		exit(1);
	s_init_con(&con, &chemp, ac, av); ///// nbr chemp!
	con.mem = allocate_memory(chemp);
	add_champions(&con, ac, av, chemp->next);
	init_ncurses(&con);
	while (con.cycl_to_die > 0 && con.proc)
	{
		//printf("cycl: %d, %d\n", con.cycl, con.cycl_to_die);
		if (s_check_cycl(&con))
		{
			if ((con.cycl_to_die -= CYCLE_DELTA) <= 0)
				break ;
			con.m_check = 0;
			s_null_chemp(&con);
		}
		// vm_show_map_win(con);
		// timeout(100);
		// c = getch();
		// if (c == 'p')
		// {
		// 	 timeout(-1);
		// 	getch();
		// 	 timeout(10);
		// }
		if (con.cycl >= con.dump && !(con.cycl % step))
		{
			vm_show_map_win(con);
			while (read(0, &k, 1) > 0 && k != 's')
			{
				if (k == 'e')
					step++;
				if (k == 'q' && step > 1)
					step--;
			}
		}
		vm_hendl_proc(&con);
		con.cycl++;
		con.cycl_die_per++;
	}
	vm_show_map_win(con);
	getch();
	vm_show_map_win(con);
	getch();
	endwin();
//	vm_give_winer(con);
	return (0);
}
