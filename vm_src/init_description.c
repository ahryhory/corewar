/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_description.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:32:40 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/12 14:32:41 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		init_description(void)
{
	ft_strcpy(g_optab[0].description, "alive");
	ft_strcpy(g_optab[1].description, "load");
	ft_strcpy(g_optab[2].description, "store");
	ft_strcpy(g_optab[3].description, "addition");
	ft_strcpy(g_optab[4].description, "substraction");
	ft_strcpy(g_optab[5].description, "and r1, r2, r3 r1 & r2 -> r3");
	ft_strcpy(g_optab[6].description, "or r1, r2, r3 r1 | r2 -> r3");
	ft_strcpy(g_optab[7].description, "xor r1, r2, r3 r1 ^ r2 -> r3");
	ft_strcpy(g_optab[8].description, "jump if carry == 1");
	ft_strcpy(g_optab[9].description, "load index");
	ft_strcpy(g_optab[10].description, "store index");
	ft_strcpy(g_optab[11].description, "fork");
	ft_strcpy(g_optab[12].description, "long load");
	ft_strcpy(g_optab[13].description, "long load index");
	ft_strcpy(g_optab[14].description, "long fork");
	ft_strcpy(g_optab[15].description, "aff");
}
