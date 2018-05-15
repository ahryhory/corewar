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

#include "asm.h"

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
}
