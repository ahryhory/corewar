/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_show_map_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:08:07 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/01 15:55:32 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	init_proc(t_con *con)
{
	t_proc	*proc;

	proc = con->proc;
	while (proc)
	{
		con->mem[proc->index].proc = 1;
		proc = proc->next;
	}
}

static void	del_proc(t_con *con)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		con->mem[i].proc = 0;
		i++;
	}
}

static void	draw_proc(t_con con, int i, int row, int *column)
{
	wattron(con.bytes_win, COLOR_PAIR(con.mem[i].chemp->color + 5));
	mvwprintw(con.bytes_win, row, *column, "%2.2x", con.mem[i].byte);
	*column += 2;
	wattroff(con.bytes_win, COLOR_PAIR(con.mem[i].chemp->color + 5));
	mvwprintw(con.bytes_win, row, (*column)++, " ");
}

static void	start(t_con *con, int *i, int *row, int *column)
{
	werase(con->bytes_win);
	werase(con->info_win);
	box(con->bytes_win, 0, 0);
	box(con->info_win, 0, 0);
	init_proc(con);
	*i = 0;
	*row = 1;
	*column = 2;
}

void		vm_show_map_win(t_con con)
{
	int		i;
	int		row;
	int		column;

	start(&con, &i, &row, &column);
	while (i < MEM_SIZE)
	{
		if (con.mem[i].proc)
			draw_proc(con, i, row, &column);
		else
			draw_color(con, i, row, &column);
		i++;
		if (i % 64 == 0)
		{
			row++;
			column = 2;
		}
	}
	del_proc(&con);
	draw_info(con);
	wrefresh(con.bytes_win);
	wrefresh(con.info_win);
}
