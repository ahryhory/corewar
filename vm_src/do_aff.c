/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:32:54 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/02 12:30:07 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_aff(t_con *con, int index, t_proc *proc)
{
	char	c;

	c = proc->r[con->mem[get_index(index, 2)].byte - 1] % 256;
	if (g_flag.a)
	{
		ft_putstr("Aff: ");
		ft_putchar(c);
		ft_putchar('\n');
	}
}
