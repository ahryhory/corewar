/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:28:53 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/02 12:16:49 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		draw_chemps(t_con con, int *row)
{
	t_chemp		*chemp;

	chemp = con.chemp;
	while (chemp)
	{
		if (chemp->champ_name[0] != '\0')
		{
			mvwprintw(con.info_win, (*row)++, 2, "Player %d :",
					vm_give_fbyte(chemp->nbr));
			wattron(con.info_win, COLOR_PAIR(chemp->color));
			mvwprintw(con.info_win, (*row)++, 4, "%.55s", chemp->champ_name);
			wattroff(con.info_win, COLOR_PAIR(chemp->color));
			mvwprintw(con.info_win, (*row)++, 4, "%-35s %d", "Last live :",
					chemp->cycl_live);
			mvwprintw(con.info_win, (*row)++, 4, "%-35s %d",
					"Lives in current period :", chemp->live_icp);
		}
		*row += 1;
		chemp = chemp->next;
	}
}

static int		find_count(t_chemp *chemp, int tot)
{
	float	ch;

	ch = (float)chemp->live_icp / (float)tot * 100.;
	ch = 52. * (float)ch / 100.;
	return ((int)ch);
}

static void		draw_line(t_chemp *chemp, t_con con, int *row, int tot)
{
	int			col;
	int			count;

	while (chemp)
	{
		if (chemp->champ_name[0] != '\0')
		{
			col = 3;
			mvwprintw(con.info_win, *row, col++, "[");
			if (tot != 0)
			{
				count = find_count(chemp, tot);
				while (count-- > 0)
				{
					wattron(con.info_win, COLOR_PAIR(chemp->color));
					mvwprintw(con.info_win, *row, col++, "-");
					wattroff(con.info_win, COLOR_PAIR(chemp->color));
				}
			}
			mvwprintw(con.info_win, (*row)++, col++, "|");
		}
		chemp = chemp->next;
	}
}

static void		draw_lines_breakdown(t_con con, int *row)
{
	int			tot;
	t_chemp		*chemp;

	chemp = con.chemp;
	tot = 0;
	while (chemp)
	{
		if (chemp->champ_name[0] != '\0')
			tot += chemp->live_icp;
		chemp = chemp->next;
	}
	mvwprintw(con.info_win, (*row)++, 2, "Live breakdown for current period :");
	draw_line(con.chemp, con, row, tot);
	*row += 2;
}

void			draw_info(t_con con)
{
	int			row;

	row = 2;
	wattron(con.info_win, A_BOLD);
	mvwprintw(con.info_win, row, 2, "%-15s %d", "Timeout :", con.step);
	row += 2;
	mvwprintw(con.info_win, row, 2, "%-15s %d", "Cycle :", con.cycl);
	row += 2;
	mvwprintw(con.info_win, row, 2, "%-15s %d", "Processes :",
		vm_count_proc(con.proc));
	row += 2;
	draw_chemps(con, &row);
	draw_lines_breakdown(con, &row);
	mvwprintw(con.info_win, row, 2, "%-15s %d", "CYCLE_TO_DIE :",
		con.cycl_to_die);
	row += 2;
	mvwprintw(con.info_win, row, 2, "%-15s %d", "CYCLE_DELTA :",
		CYCLE_DELTA);
	row += 2;
	mvwprintw(con.info_win, row, 2, "%-15s %d", "NBR_LIVE :", NBR_LIVE);
	row += 2;
	mvwprintw(con.info_win, row, 2, "%-15s %d", "MAX_CHECKS :", MAX_CHECKS);
	usage_info(con, &row);
	wattroff(con.info_win, A_BOLD);
}
