/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:12:51 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/27 15:09:33 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

int				main(int argc, char **argv)
{
	t_data		data;
	t_info		info;

	argc++;
	init_optab();
	info.line = 0;
	info.num = 0;
	info.real_num = 0;
	if (ft_strequ(FLAG_A, argv[1]))
	{
		data = parse(argv[2], info);
		check_commands(data.command);
		flag_a(&data);
		return (0);
	}
	data = parse(argv[1], info);
	check_commands(data.command);
	write_byte(data, argv[1]);
	ft_putstr("Writing output program to ");
	ft_putstr(argv[1]);
	ft_putendl("cor");
	return (0);
}
