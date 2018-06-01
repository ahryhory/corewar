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

void	init_proc(t_con *con)
{
	t_proc	*proc;

	proc = con->proc;
	while (proc)
	{
		con->mem[proc->index].proc = 1;
		proc = proc->next;
	}
}

void	del_proc(t_con *con)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		con->mem[i].proc = 0;
		i++;
	}
}

void	draw_proc(t_con con, int i, int row, int *column)
{
	wattron(con.bytes_win, COLOR_PAIR(con.mem[i].chemp->color + 5));
	mvwprintw(con.bytes_win , row, *column, "%2.2x", con.mem[i].byte);
	*column += 2;
	wattroff(con.bytes_win, COLOR_PAIR(con.mem[i].chemp->color + 5));
	mvwprintw(con.bytes_win , row, (*column)++, " ");
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
		wattron(con.bytes_win, COLOR_PAIR(10));
		mvwprintw(con.bytes_win , row, *column, "%2.2x ", con.mem[i].byte);
		*column += 3;
		wattroff(con.bytes_win, COLOR_PAIR(10));
	}
}

void	draw_info(t_con con)
{
		t_chemp		*chemp;
		int			row;

		wattron(con.info_win, A_BOLD);
		mvwprintw(con.info_win, 1, 2, "%-15s %d", "Cycl:", con.cycl);
		mvwprintw(con.info_win, 3, 2, "%-15s %d", "Step:", con.step);
		mvwprintw(con.info_win, 5, 2, "%-15s %d", "Cycl_to_die:", con.cycl_to_die);
		mvwprintw(con.info_win, 7, 2, "%-15s %d", "Proces:", vm_count_proc(con.proc));
		chemp = con.chemp;
		row = 9;
		while (chemp)
		{
			if (chemp->champ_name[0] != '\0')
			{
				mvwprintw(con.info_win, row++, 2, "Player %d :", (char)chemp->nbr[3]);
				wattron(con.info_win, COLOR_PAIR(chemp->color));
				mvwprintw(con.info_win, row++, 4, "%s", chemp->champ_name);
				wattroff(con.info_win, COLOR_PAIR(chemp->color)); 
				mvwprintw(con.info_win, row++, 4, "cycl_live : %d", chemp->cycl_live);
				mvwprintw(con.info_win, row++, 4, "live_icp : %d", chemp->live_icp);
			}
			row++;
			chemp = chemp->next;
		}
		wattroff(con.info_win, A_BOLD);
}

void	vm_show_map_win(t_con con)
{
	int		i;
	int		row;
	int		column;

	werase(con.bytes_win);
	werase(con.info_win);
	box(con.bytes_win, 0, 0);
	box(con.info_win, 0, 0);
	init_proc(&con);
	i = 0;
	row = 1;
	column = 2;
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
