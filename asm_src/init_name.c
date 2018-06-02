/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:24:48 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/12 14:24:49 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		init_name(void)
{
	ft_strcpy(g_optab[0].name, "live");
	ft_strcpy(g_optab[1].name, "ld");
	ft_strcpy(g_optab[2].name, "st");
	ft_strcpy(g_optab[3].name, "add");
	ft_strcpy(g_optab[4].name, "sub");
	ft_strcpy(g_optab[5].name, "and");
	ft_strcpy(g_optab[6].name, "or");
	ft_strcpy(g_optab[7].name, "xor");
	ft_strcpy(g_optab[8].name, "zjmp");
	ft_strcpy(g_optab[9].name, "ldi");
	ft_strcpy(g_optab[10].name, "sti");
	ft_strcpy(g_optab[11].name, "fork");
	ft_strcpy(g_optab[12].name, "lld");
	ft_strcpy(g_optab[13].name, "lldi");
	ft_strcpy(g_optab[14].name, "lfork");
	ft_strcpy(g_optab[15].name, "aff");
}
