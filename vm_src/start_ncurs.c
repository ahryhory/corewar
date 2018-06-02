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

<<<<<<< HEAD
static void		sigfun(int sig)
=======
static void sigfun(int sig)
>>>>>>> 9a88221528099d0f7b1503a5789988804b1b86f7
{
	system("killall afplay");
	(void)signal(SIGINT, SIG_DFL);
	endwin();
	exit(0);
}

<<<<<<< HEAD
void			start_ncurs(int *start, t_con *con)
=======
void	start_ncurs(int *start, t_con *con)
>>>>>>> 9a88221528099d0f7b1503a5789988804b1b86f7
{
	int			c;

	(void)signal(SIGINT, sigfun);
	timeout(0);
	c = getch();
	if (c == ' ' || c == 's')
	{
		system("killall -STOP afplay");
		*start = 0;
	}
	usleep(con->step);
	vm_show_map_win(*con);
	while (!*start)
	{
		vm_show_map_win(*con);
		read(0, &c, 1);
		if ((char)c == ' ')
		{
			system("killall -CONT afplay");
			*start = 1;
		}
		if ((char)c == 's')
			break ;
		if ((char)c == 'e')
			con->step += 1000;
		if ((char)c == 'q' && con->step > 1)
			con->step -= 1000;
	}
}
