/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_give_winer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:36:21 by iseletsk          #+#    #+#             */
/*   Updated: 2018/06/13 18:46:37 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	end_drow(t_con con)
{
	vm_show_map_win(con);
	read(0, 0, 1);
	endwin();
	system("./end_proc");
}

void		vm_give_winer(t_con *con)
{
	t_chemp	*w_chemp;
	char	*str;

	w_chemp = con->winer;
	if (!w_chemp)
	{
		w_chemp = con->chemp;
		while (w_chemp->next)
			w_chemp = w_chemp->next;
	}
	if (g_flag.v)
		end_drow(*con);
	str = "Player ";
	write(1, str, ft_strlen(str));
	ft_putnbr(vm_give_fbyte(w_chemp->nbr));
	str = ", \"";
	write(1, str, ft_strlen(str));
	ft_putstr(w_chemp->champ_name);
	write(1, "\", has won!\n", 12);
}
