/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lable_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:32:59 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/12 14:33:00 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_lable_size(void)
{
	g_optab[0].lable_size = 4;
	g_optab[1].lable_size = 4;
	g_optab[2].lable_size = 4;
	g_optab[3].lable_size = 4;
	g_optab[4].lable_size = 4;
	g_optab[5].lable_size = 4;
	g_optab[6].lable_size = 4;
	g_optab[7].lable_size = 4;
	g_optab[8].lable_size = 2;
	g_optab[9].lable_size = 2;
	g_optab[10].lable_size = 2;
	g_optab[11].lable_size = 2;
	g_optab[12].lable_size = 4;
	g_optab[13].lable_size = 2;
	g_optab[14].lable_size = 2;
	g_optab[15].lable_size = 4;
}
