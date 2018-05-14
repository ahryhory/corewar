/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:12:51 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/10 11:12:52 by ybohusev         ###   ########.fr       */
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
	t_data	data;
	t_info	info;
	
	init_optab();
	if (ft_strequ(FLAG_A, argv[1]))
	{
		data = parse(argv[2], info);
		flag_a(&data);
		// system("leaks asm");
		return (1);
	}
	data = parse(argv[1], info);
	write_byte(data, argv[1]);
	// system("leaks asm");
	return (0);
}
