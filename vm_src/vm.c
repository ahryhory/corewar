/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:30:20 by iseletsk          #+#    #+#             */
/*   Updated: 2018/06/02 11:31:14 by iseletsk         ###   ########.fr       */
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
	int			c;

	vm_init_flag(ac, av);
	init_optab();
	start = 0;
	con.step = 100;
	if (ac == 1)
		exit(1);
	s_init_con(&con, &chemp);
	con.mem = allocate_memory(chemp);
	add_champions(&con, av, chemp->next);
	vm_salution(con, av);
	if (g_flag.v)
		init_ncurses(&con);
	//system("afplay sound/1.mp3 &");
	while (con.cycl_to_die > 0 && con.proc)
	{
		vm_check_proc(&con);
		if (s_check_cycl(&con))
		{
			if ((con.cycl_to_die -= CYCLE_DELTA) <= 0)
				break ;
			con.m_check = 0;
			s_null_chemp(&con);
		}
		if (g_flag.v)
		{
			timeout(0);
			usleep(con.step);
			c = getch();
			if (c == ' ' || c == 's')
				start = 0;
			vm_show_map_win(con);
			c = getch();
			while (!start)
			{
				vm_show_map_win(con);
				read(0, &c, 1);
				if ((char)c == ' ')
					start = 1;
				if ((char)c == 's')
					break ;
				if ((char)c == 'e')
					con.step++;
				if ((char)c == 'q' && con.step > 1)
					con.step--;
			}
			if (c == ' ' || c == 's')
				start = 0;
		}
		if (g_flag.dump != 0 && con.cycl == g_flag.dump && !g_flag.v)
			write_dump(con.mem);
		vm_hendl_proc(&con);
		con.cycl++;
		con.cycl_die_per++;
	}
	if (g_flag.v)
	{
		vm_show_map_win(con);
		read(0, 0, 1);
		endwin();
	}
	//system("pkill afplay");
	vm_give_winer(&con);
	return (0);
}
