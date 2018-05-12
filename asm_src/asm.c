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

static	void	init_optab()
{
	t_optab		optab[17];

	optab[0].name = ft_strdup("live");
	optab[1].name = ft_strdup("ld");
	optab[2].name = ft_strdup("st");
	optab[3].name = ft_strdup("add");
	optab[4].name = ft_strdup("sub");
	optab[5].name = ft_strdup("and");
	optab[6].name = ft_strdup("or");
	optab[7].name = ft_strdup("xor");
	optab[8].name = ft_strdup("zjmp");
	optab[9].name = ft_strdup("ldi");
	optab[10].name = ft_strdup("sti");
	optab[11].name = ft_strdup("fork");
	optab[12].name = ft_strdup("lld");
	optab[13].name = ft_strdup("lldi");
	optab[14].name = ft_strdup("lfork");
	optab[15].name = ft_strdup("aff");
	optab[16].name = NULL;
}

int				main(int argc, char **argv)
{
	t_data	data;
	
	data = parse(argv[1]);
	write_byte(data, argv[1]);
	return (0);
}
