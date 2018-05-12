/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:32:09 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/12 14:32:10 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		init_args_number(void)
{
	g_optab[0].args_number = 1;
	g_optab[1].args_number = 2;
	g_optab[2].args_number = 2;
	g_optab[3].args_number = 3;
	g_optab[4].args_number = 3;
	g_optab[5].args_number = 3;
	g_optab[6].args_number = 3;
	g_optab[7].args_number = 3;
	g_optab[8].args_number = 1;
	g_optab[9].args_number = 3;
	g_optab[10].args_number = 3;
	g_optab[11].args_number = 1;
	g_optab[12].args_number = 2;
	g_optab[13].args_number = 3;
	g_optab[14].args_number = 1;
	g_optab[15].args_number = 1;
}
