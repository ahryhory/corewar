/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opcode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:32:24 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/12 14:32:24 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	init_code(void)
{
	g_optab[0].code = 0x01;
	g_optab[2].code = 0x02;
	g_optab[3].code = 0x03;
	g_optab[4].code = 0x04;
	g_optab[5].code = 0x05;
	g_optab[6].code = 0x06;
	g_optab[7].code = 0x07;
	g_optab[8].code = 0x08;
	g_optab[9].code = 0x09;
	g_optab[10].code = 0x0a;
	g_optab[11].code = 0x0b;
	g_optab[12].code = 0x0c;
	g_optab[13].code = 0x0d;
	g_optab[14].code = 0x0e;
	g_optab[15].code = 0x0f;
	g_optab[16].code = 0x10;
}

void		init_opcode(void)
{
	ft_strcpy(g_optab[0].opcode, "01");
	ft_strcpy(g_optab[1].opcode, "02");
	ft_strcpy(g_optab[2].opcode, "03");
	ft_strcpy(g_optab[3].opcode, "04");
	ft_strcpy(g_optab[4].opcode, "05");
	ft_strcpy(g_optab[5].opcode, "06");
	ft_strcpy(g_optab[6].opcode, "07");
	ft_strcpy(g_optab[7].opcode, "08");
	ft_strcpy(g_optab[8].opcode, "09");
	ft_strcpy(g_optab[9].opcode, "0a");
	ft_strcpy(g_optab[10].opcode, "0b");
	ft_strcpy(g_optab[11].opcode, "0c");
	ft_strcpy(g_optab[12].opcode, "0d");
	ft_strcpy(g_optab[13].opcode, "0e");
	ft_strcpy(g_optab[14].opcode, "0f");
	ft_strcpy(g_optab[15].opcode, "10");
	init_code();
}
