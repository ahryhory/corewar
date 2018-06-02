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

void	start_ncurs(int *start, t_con *con)
{
	int		c;

	timeout(0);
	c = getch();
	if (c == ' ' || c == 's')
		*start = 0;
	usleep(con->step);
	c = getch();
	if (c == ' ' || c == 's')
		*start = 0;
	vm_show_map_win(*con);
	c = getch();
	while (!*start)
	{
		vm_show_map_win(*con);
		read(0, &c, 1);
		if ((char)c == ' ')
			*start = 1;
		if ((char)c == 's')
			break ;
		if ((char)c == 'e')
			con->step += 1000;
		if ((char)c == 'q' && con->step > 1)
			con->step -= 1000;
	}
}
