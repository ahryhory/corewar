/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:33:20 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/30 16:16:44 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_ldi(t_con *con, int index, unsigned int *n, t_proc *proc)
{
	unsigned int		arg_1;
	unsigned int		arg_2;
	int		step;
	int		step2;

	//printf("COMMAND: ldi\n");
	step = 0;
	step2 = 0;
	arg_1 = 0;
	arg_2 = 0;
	if (n[0] == 1 && (step = 1))
		arg_1 = (short int)proc->r[con->mem[get_index(index, 2)].byte - 1];
	else if ((step = 2))
		arg_1 = (short int)get_nbr(con, get_index(index, 2), 2);
	if (n[0] == 3)
		arg_1 = get_nbr(con, get_index(index, arg_1 % IDX_MOD), 4);
	if (n[1] == 1 && (step2 = 1))
		arg_2 = (short int)proc->r[con->mem[get_index(index, 2 + step)].byte
			- 1];
	else if (n[1] == 2 && (step2 = 2))
		arg_2 = (short int)get_nbr(con, get_index(index, step + 2), 2);
	proc->r[con->mem[get_index(index, 2 + step + step2)].byte - 1] =
	get_nbr(con, get_index(index, (short int)(arg_1 + arg_2) % IDX_MOD), 4);
}
/*
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

void	do_ldi(t_con *con, int index, unsigned int *n, t_proc *proc)
{
	long int		arg_1;
	long int		arg_2;
	int				step;
	int				step2;

	s_init(&arg_1, &arg_2, &step);
	step2 = 0;
	if (n[0] == 1 && (step = 1))
		arg_1 = proc->r[con->mem[get_index(index, 2)].byte - 1];
	else if ((step = 2))
		arg_1 = (short int)get_nbr(con, get_index(index, 2), 2);
	if (n[0] == 3)
		arg_1 = get_nbr(con, get_index(index, arg_1 % IDX_MOD), 4);
	if (n[1] == 1 && (step2 = 1))
		arg_2 = proc->r[con->mem[get_index(index, 2 + step)].byte - 1];
	else if (n[1] == 2 && (step2 = 2))
		arg_2 = (short int)get_nbr(con, get_index(index, step + 2), 2);
	proc->r[con->mem[get_index(index, 2 + step + step2)].byte - 1] =
	get_nbr(con, s_help_index(index, arg_1, arg_2, n), 4);
}*/
