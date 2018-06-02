/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_give_winer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:36:21 by iseletsk          #+#    #+#             */
/*   Updated: 2018/06/02 11:34:26 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	s_give_nbr(int *nbr)
{
	int		res;

	res = 0;
	res += (char)(nbr[0] & 4278190080);
	res += (char)(nbr[1] & 16711680);
	res += (char)(nbr[2] & 65280);
	res += (char)(nbr[3] & 255);
	return (res);
}

void		vm_give_winer(t_con *con)
{
	t_chemp	*w_chemp;
	t_chemp	*chemp;
	char	*str;

	chemp = con->chemp;
	w_chemp = chemp->next;
	while (chemp)
	{
		if (chemp->cycl_live >= w_chemp->cycl_live)
			w_chemp = chemp;
		chemp = chemp->next;
	}
	str = "Player ";
	write(1, str, ft_strlen(str));
	ft_putnbr(s_give_nbr(w_chemp->nbr));
	str = ", \"";
	write(1, str, ft_strlen(str));
	ft_putstr(w_chemp->champ_name);
	write(1, "\", has won!\n", 12);
}
