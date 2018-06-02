/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:29:03 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/01 12:29:04 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	draw_color(t_con con, int i, int row, int *column)
{
	if (con.mem[i].light + 50 > con.cycl && con.mem[i].light != 0)
	{
		wattron(con.bytes_win, COLOR_PAIR(con.mem[i].chemp->color) | A_BOLD);
		mvwprintw(con.bytes_win, row, *column, "%2.2x ", con.mem[i].byte);
		*column += 3;
		wattroff(con.bytes_win, COLOR_PAIR(con.mem[i].chemp->color) | A_BOLD);
	}
	else if (con.mem[i].chemp->color != 0)
	{
		wattron(con.bytes_win, COLOR_PAIR(con.mem[i].chemp->color));
		mvwprintw(con.bytes_win, row, *column, "%2.2x ", con.mem[i].byte);
		*column += 3;
		wattroff(con.bytes_win, COLOR_PAIR(con.mem[i].chemp->color));
	}
	else
	{
		wattron(con.bytes_win, COLOR_PAIR(10));
		mvwprintw(con.bytes_win, row, *column, "%2.2x ", con.mem[i].byte);
		*column += 3;
		wattroff(con.bytes_win, COLOR_PAIR(10));
	}
}
