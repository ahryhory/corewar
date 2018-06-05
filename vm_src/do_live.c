/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:33:49 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/05 16:17:19 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	s_init(int *nbr, int index, t_con *con)
{
	nbr[0] = con->mem[get_index(index, 1)].byte;
	nbr[1] = con->mem[get_index(index, 2)].byte;
	nbr[2] = con->mem[get_index(index, 3)].byte;
	nbr[3] = con->mem[get_index(index, 4)].byte;
}

static void	s_alive(t_con *con, t_chemp *chemp)
{
	con->winer = chemp;
	if (g_flag.v)
		return ;
	ft_putstr("A process shows that player ");
	ft_putnbr(-(char)chemp->nbr[3]);
	write(1, " (", 2);
	ft_putstr(chemp->champ_name);
	ft_putstr(") is alive\n");
}

void		do_live(t_con *con, int index, t_proc *proc)
{
	int		nbr[4];
	int		i;
	t_chemp	*chemp;

	chemp = con->chemp->next;
	con->live++;
	if (proc->live <= 1)
		proc->live++;
	s_init(nbr, index, con);
	while (chemp)
	{
		i = -1;
		while (++i < 4)
		{
			if (nbr[i] != chemp->nbr[i])
				break ;
			if (i <= 2)
				continue;
			chemp->cycl_live = con->cycl + 1;
			chemp->live_icp++;
			s_alive(con, chemp);
			return ;
		}
		chemp = chemp->next;
	}
}
