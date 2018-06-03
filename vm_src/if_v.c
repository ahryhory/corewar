/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_v.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:35:43 by ybohusev          #+#    #+#             */
/*   Updated: 2018/06/03 16:35:45 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	if_v(t_con *con)
{
	if (g_flag.v)
	{
		(void)signal(SIGTSTP, sigtstp);
		(void)signal(SIGINT, sigint);
		system("printf \"\e[8;66;256;t\"");
		system("afplay sound/1.mp3 &");
		system("killall -STOP afplay");
		init_ncurses(con);
	}
}
