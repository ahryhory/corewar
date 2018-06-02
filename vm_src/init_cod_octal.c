/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cod_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:32:52 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/12 14:32:53 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_cod_octal(void)
{
	g_optab[0].cod_octal = 0;
	g_optab[1].cod_octal = 1;
	g_optab[2].cod_octal = 1;
	g_optab[3].cod_octal = 1;
	g_optab[4].cod_octal = 1;
	g_optab[5].cod_octal = 1;
	g_optab[6].cod_octal = 1;
	g_optab[7].cod_octal = 1;
	g_optab[8].cod_octal = 0;
	g_optab[9].cod_octal = 1;
	g_optab[10].cod_octal = 1;
	g_optab[11].cod_octal = 0;
	g_optab[12].cod_octal = 1;
	g_optab[13].cod_octal = 1;
	g_optab[14].cod_octal = 0;
	g_optab[15].cod_octal = 1;
}
