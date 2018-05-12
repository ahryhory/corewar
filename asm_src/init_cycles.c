/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cycles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:32:34 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/12 14:32:35 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		init_cycles(void)
{
	g_optab[0].cycles = 10;
	g_optab[1].cycles = 5;
	g_optab[2].cycles = 5;
	g_optab[3].cycles = 10;
	g_optab[4].cycles = 10;
	g_optab[5].cycles = 6;
	g_optab[6].cycles = 6;
	g_optab[7].cycles = 6;
	g_optab[8].cycles = 20;
	g_optab[9].cycles = 25;
	g_optab[10].cycles = 25;
	g_optab[11].cycles = 800;
	g_optab[12].cycles = 10;
	g_optab[13].cycles = 50;
	g_optab[14].cycles = 1000;
	g_optab[15].cycles = 2;
}
