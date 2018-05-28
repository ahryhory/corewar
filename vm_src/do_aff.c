/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:32:54 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/20 15:20:01 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_aff(t_con *con, int index, t_proc *proc)
{
	char	c;

	//printf("COMMAND: aff\n");
	c = proc->r[con->mem[get_index(index, 2)].byte - 1] % 256;
	ft_putchar(c);
}
