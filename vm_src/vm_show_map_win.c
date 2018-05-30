/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_show_map_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:08:07 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/28 16:08:10 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	draw_proc(t_proc *proc, t_con con, int i, int *draw, int row, int *column)
{
	while (proc)
	{
		if (proc->index == i)
		{
			wattron(con.bytes_win, COLOR_PAIR(con.mem[i].chemp->color + 5));
			mvwprintw(con.bytes_win , row, *column, "%2.2x", con.mem[i].byte);
			*column += 2;
			wattroff(con.bytes_win, COLOR_PAIR(con.mem[i].chemp->color + 5));
			mvwprintw(con.bytes_win , row, (*column)++, " ");
			*draw = 0;
			break ;
		}
		proc = proc->next;
	}
}

void	draw_color(t_con con, int i, int row, int *column)
{
	if (con.mem[i].light + 50 > con.cycl && con.mem[i].light != 0)
	{
		wattron(con.bytes_win, COLOR_PAIR(con.mem[i].chemp->color) | A_BOLD);
		mvwprintw(con.bytes_win , row, *column, "%2.2x ", con.mem[i].byte);
		*column += 3;
		wattroff(con.bytes_win, COLOR_PAIR(con.mem[i].chemp->color) | A_BOLD);
	}
	else if (con.mem[i].chemp->color != 0)
	{
		wattron(con.bytes_win, COLOR_PAIR(con.mem[i].chemp->color));
		mvwprintw(con.bytes_win , row, *column, "%2.2x ", con.mem[i].byte);
		*column += 3;
		wattroff(con.bytes_win, COLOR_PAIR(con.mem[i].chemp->color));
	}
	else
	{
		wattron(con.bytes_win, A_DIM);
		mvwprintw(con.bytes_win , row, *column, "%2.2x ", con.mem[i].byte);
		*column += 3;
		wattroff(con.bytes_win, A_DIM);
	}
}

void	draw_info(t_con con)
{
		mvwprintw(con.info_win, 1, 2, "%-15s %d", "Cycl:", con.cycl);
		mvwprintw(con.info_win, 2, 2, "%-15s %d", "Cycl_to_die:", con.cycl_to_die);
		mvwprintw(con.info_win, 3, 2, "%-15s %d", "Proces:", vm_count_proc(con.proc));
}

void	vm_show_map_win(t_con con)
{
	int		i;
	int		draw;
	int		row;
	int		column;

	werase(con.bytes_win);
	werase(con.info_win);
	box(con.bytes_win, 0, 0);
	box(con.info_win, 0, 0);
	i = 0;
	row = 1;
	column = 2;
	while (i < MEM_SIZE)
	{
		draw = 1;
		draw_proc(con.proc, con, i, &draw, row, &column);
		if (draw)
			draw_color(con, i, row, &column);
		i++;
		if (i % 64 == 0)
		{
			row++;
			column = 2;
		}
	}
	draw_info(con);
	wrefresh(con.bytes_win);
	wrefresh(con.info_win);
}
