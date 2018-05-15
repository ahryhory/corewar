/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:40:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/15 12:40:17 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		init_optab(void)
{
	init_name();
	init_args_number();
	init_args();
	init_opcode();
	init_cycles();
	init_description();
	init_carry();
	init_cod_octal();
	init_lable_size();
}

int				main(int ac, char **av)
{
	t_memory	*memory;
	int			i;

	init_optab();
	if (ac == 1)
		exit(1);
	memory = allocate_memory();
	add_champions(&memory, ac, av);
	// i = 0;
	// while (i < MEM_SIZE)
	// {
	// 	printf("%d ", memory[i].byte);
	// 	i++;
	// }
	return (0);
}
