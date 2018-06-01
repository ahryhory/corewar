/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:35:07 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/01 15:39:16 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static unsigned int	s_arg_ind(t_con *con, int index)
{
	unsigned int	arg;
	int				step;

	step = (short int)get_nbr(con, index, 2) % IDX_MOD;
	arg = get_nbr(con, get_index(index, step), 4);
	return (arg);
}

static void			s_init(unsigned int *num_1, unsigned int *num_2,
		unsigned int *step)
{
	*num_1 = 0;
	*num_2 = 0;
	*step = 0;
}

void				do_or(t_con *con, int index, unsigned int *n, t_proc *proc)
{
	unsigned int	num_1;
	unsigned int	num_2;
	unsigned int	step;
	unsigned int	step2;

	s_init(&num_1, &num_2, &step);
	step2 = 0;
	if (n[0] == 1 && (step = 1))
		num_1 = proc->r[con->mem[get_index(index, 2)].byte - 1];
	else if (n[0] == 2 && (step = 4))
		num_1 = get_nbr(con, get_index(index, 2), 4);
	else if (n[0] == 3 && (step = 2))
		num_1 = s_arg_ind(con, get_index(index, 2));
	if (n[1] == 1 && (step2 = 1))
		num_2 = proc->r[con->mem[get_index(index, 2 + step)].byte - 1];
	else if (n[1] == 2 && (step2 = 4))
		num_2 = get_nbr(con, get_index(index, 2 + step), 4);
	else if (n[1] == 3 && (step2 = 2))
		num_2 = s_arg_ind(con, get_index(index, 2 + step));
	if ((proc->r[con->mem[get_index(index, 2 + step + step2)].byte - 1] =
														num_1 | num_2) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
