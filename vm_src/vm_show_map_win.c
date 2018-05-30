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

void	draw_proc(t_proc *proc, t_mem *mem, int i, int *draw)
{
	while (proc)
	{
		if (proc->index == i)
		{
			attron(COLOR_PAIR(1));
			printw("%2.2x", mem[i].byte);
			attroff(COLOR_PAIR(1));
			printw(" ");
			*draw = 0;
			break ;
		}
		proc = proc->next;
	}
}

void	draw_color(t_proc *proc, t_mem *mem, int i, int *draw, int cycl)
{
	if (mem[i].light + 50 > cycl && mem[i].light != 0)
	{
		attron(COLOR_PAIR(mem[i].chemp->color + 5));
		printw("%2.2x", mem[i].byte);
		attroff(COLOR_PAIR(mem[i].chemp->color + 5));
		printw(" ");
		*draw = 0;
	}
	else if (mem[i].chemp->color != 0)
	{
		attron(COLOR_PAIR(mem[i].chemp->color + 1));
		printw("%2.2x", mem[i].byte);
		attroff(COLOR_PAIR(mem[i].chemp->color + 1));
		printw(" ");
		*draw = 0;
	}
}

void	vm_show_map_win(t_con con)
{
	int		i;
	int		j;
	int		draw;
	t_proc	*proc;

	erase();
	i = 0;
	while (i < MEM_SIZE)
	{
		draw = 1;
		draw_proc(con.proc, con.mem, i, &draw);
		if (draw)
			draw_color(con.proc, con.mem, i, &draw, con.cycl);
		if (draw)
			printw("%2.2x ", con.mem[i].byte);
		i++;
		if (i % 64 == 0)
		{
			if (j == 0)
				printw("%20s %d", "cycl:          ", con.cycl);
			if (j == 2)
				printw("%20s %d", "cycl_to_day:   ", con.cycl_to_die);
			if (j == 3)
				printw("%20s %d", "Proces:", vm_count_proc(con.proc));
			printw("\n");
		}
	}
	refresh();
}
