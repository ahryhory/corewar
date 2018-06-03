/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:24:57 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/03 14:25:07 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	usage_info(t_con con, int *row)
{
	*row += 5;
	mvwprintw(con.info_win, (*row), 1, "                 CONTROL PANEL");
	*row += 2;
	mvwprintw(con.info_win, (*row)++, 2, "SPACE -     pause or start");
	mvwprintw(con.info_win, (*row)++, 2,
		"q     -     decreases timeout (only on the pause)");
	mvwprintw(con.info_win, (*row)++, 2,
		"r     -     increases timeout (only on the pause)");
	mvwprintw(con.info_win, (*row)++, 2,
		"m     -     sound on/off");
	mvwprintw(con.info_win, (*row)++, 2,
		"s     -     cycle per step");
}
