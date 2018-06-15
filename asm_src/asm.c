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

static void		print_usage(void)
{
	ft_putendl("usage: ./asm [-a] <sourcefile.s>");
	ft_putstr("-a : Instead of creating a .cor file, outputs ");
	ft_putstr("a stripped and annotated version of the ");
	ft_putendl("code to the standard output");
	exit(0);
}

static void		usage(int argc, char **argv)
{
	if (argc > 1 && !ft_strequ(argv[1], "-a") && argv[1][0] == '-')
		print_usage();
	if (((argc == 2 && !ft_strequ(argv[1], "-a")) || (argc == 3 &&
		ft_strequ(argv[1], "-a"))))
		return ;
	else
		print_usage();
}

int				main(int argc, char **argv)
{
	t_data		data;
	t_info		info;

	usage(argc, argv);
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
