/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:33:20 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/31 20:31:00 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	s_init(long long int *arg_1, long long int *arg_2, int *step)
{
	*arg_1 = 0;
	*arg_2 = 0;
	*step = 0;
}

void		do_ldi(t_con *con, int index, unsigned int *n, t_proc *proc)
{
	long long int	arg_1;
	long long int	arg_2;
	int				step;
	int				step2;

	s_init(&arg_1, &arg_2, &step);
	step2 = 0;
	if (n[0] == 1 && (step = 1))
		arg_1 = (unsigned int)proc->r[con->mem[get_index(index, 2)].byte - 1];
	else if ((step = 2))
		arg_1 = (short)get_nbr(con, get_index(index, 2), 2);
	if (n[0] == 3)
		arg_1 = (unsigned int)get_nbr(con, get_index(index, arg_1 % IDX_MOD)
				, 4);
	if (n[1] == 1 && (step2 = 1))
		arg_2 = (unsigned int)proc->r[con->mem[get_index(index, 2 + step)].byte
			- 1];
	else if (n[1] == 2 && (step2 = 2))
		arg_2 = (short)get_nbr(con, get_index(index, step + 2), 2);
	proc->r[con->mem[get_index(index, 2 + step + step2)].byte - 1] =
	get_nbr(con, get_index(index, (int)(arg_1 + arg_2) % IDX_MOD), 4);
}
