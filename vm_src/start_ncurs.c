/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ncurs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 12:41:02 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/02 12:41:03 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	sigfun(int sig)
{
	(void)sig;
	system("killall afplay");
	(void)signal(SIGINT, SIG_DFL);
	endwin();
	exit(0);
}

static void	cycle_pause(int *start, t_con *con, int music, int c)
{
	while (!*start)
	{
		vm_show_map_win(*con);
		read(0, &c, 1);
		if ((char)c == ' ')
		{
			if (music != 1)
				system("killall -CONT afplay");
			*start = 1;
		}
		if ((char)c == 's')
			break ;
		if ((char)c == 'e' && con->step + 1000 <= 100000)
			con->step += 10000;
		if ((char)c == 'q' && con->step - 1000 >= 0)
			con->step -= 10000;
	}
}

static void	trig_music(int c, int *music)
{
	if (c == 'm' && *music == 1)
	{
		system("killall -CONT afplay");
		*music = 0;
	}
	else if (c == 'm')
	{
		system("killall -STOP afplay");
		*music = 1;
	}
}

void		start_ncurs(int *start, t_con *con)
{
	int			c;
	static int	flag = 0;
	static int	music = 0;

	(void)signal(SIGINT, sigfun);
	timeout(0);
	c = getch();
	if (c == ' ' || c == 's')
	{
		system("killall -STOP afplay");
		*start = 0;
	}
	trig_music(c, &music);
	usleep(con->step);
	vm_show_map_win(*con);
	cycle_pause(start, con, music, c);
	if (flag++ % 100 == 0)
		system("./pidof");
}
