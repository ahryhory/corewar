/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:35:20 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/30 15:56:22 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	s_add_to_mem(t_con *con, unsigned int value, int index,
		t_chemp *chemp)
{

	con->mem[index].chemp = chemp;
	con->mem[index].byte = (value >> 24) & 255;
	con->mem[index].light = con->cycl;
	index = get_index(index, 1);
	con->mem[index].chemp = chemp;
	con->mem[index].byte = (value >> 16) & 255;
	con->mem[index].light = con->cycl;
	index = get_index(index, 1);
	con->mem[index].chemp = chemp;
	con->mem[index].byte = (value >> 8) & 255;
	con->mem[index].light = con->cycl;
	index = get_index(index, 1);
	con->mem[index].chemp = chemp;
	con->mem[index].byte = value & 255;
	con->mem[index].light = con->cycl;
}

static void	s_init(long int *arg_1, long int *arg_2, int *step)
{
	*arg_1 = 0;
	*arg_2 = 0;
	*step = 0;
}

static int	s_help_index(int index, long int a1, long int a2, unsigned  int *n)
{
	if (n[1] == 2)
		return (get_index(index, (a1 + a2) % IDX_MOD));
	return (get_index(index, (short int)(a1 + a2) % IDX_MOD));
}

void	do_sti(t_con *con, int index, unsigned int *n, t_proc *proc)
{
	long int		arg_1;
	long int		arg_2;
	unsigned int	value;
	int				step;

	s_init(&arg_1, &arg_2, &step);
	value = proc->r[con->mem[get_index(index, 2)].byte - 1];
	if (n[1] == 1 && (step = 1))
		arg_1 = proc->r[con->mem[get_index(index, 3)].byte - 1];
	else if ((step = 2))
		arg_1 = (short int)get_nbr(con, get_index(index, 3), 2);
	if (n[1] == 3)
		arg_1 = get_nbr(con, get_index(index, arg_1 % IDX_MOD), 4);
	if (n[2] == 1)
		arg_2 = proc->r[con->mem[get_index(index, 3 + step)].byte
			- 1];
	else if (n[2] == 2)
		arg_2 = (short int)get_nbr(con, get_index(index, step + 3), 2);
	s_add_to_mem(con, value, s_help_index(index, arg_1, arg_2, n), proc->chemp);
}
