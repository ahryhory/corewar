/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:32:16 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/12 14:32:17 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	init_args_1(void)
{
	g_optab[0].args[0][1] = 1;
	g_optab[1].args[0][1] = 1;
	g_optab[1].args[0][2] = 1;
	g_optab[2].args[0][0] = 1;
	g_optab[3].args[0][0] = 1;
	g_optab[4].args[0][0] = 1;
	g_optab[5].args[0][0] = 1;
	g_optab[5].args[0][1] = 1;
	g_optab[5].args[0][2] = 1;
	g_optab[6].args[0][0] = 1;
	g_optab[6].args[0][1] = 1;
	g_optab[6].args[0][2] = 1;
	g_optab[7].args[0][0] = 1;
	g_optab[7].args[0][1] = 1;
	g_optab[7].args[0][2] = 1;
	g_optab[8].args[0][1] = 1;
	g_optab[9].args[0][0] = 1;
	g_optab[9].args[0][1] = 1;
	g_optab[9].args[0][2] = 1;
	g_optab[10].args[0][0] = 1;
	g_optab[11].args[0][1] = 1;
	g_optab[12].args[0][1] = 1;
	g_optab[12].args[0][2] = 1;
	g_optab[13].args[0][0] = 1;
	g_optab[13].args[0][1] = 1;
}

static void	init_args_2(void)
{
	g_optab[13].args[0][2] = 1;
	g_optab[14].args[0][1] = 1;
	g_optab[15].args[0][0] = 1;
	g_optab[1].args[0][0] = 1;
	g_optab[2].args[0][0] = 1;
	g_optab[2].args[0][2] = 1;
	g_optab[3].args[0][0] = 1;
	g_optab[4].args[0][0] = 1;
	g_optab[5].args[0][0] = 1;
	g_optab[5].args[0][1] = 1;
	g_optab[5].args[0][2] = 1;
	g_optab[6].args[0][0] = 1;
	g_optab[6].args[0][1] = 1;
	g_optab[6].args[0][2] = 1;
	g_optab[7].args[0][0] = 1;
	g_optab[7].args[0][1] = 1;
	g_optab[7].args[0][2] = 1;
	g_optab[9].args[0][0] = 1;
	g_optab[9].args[0][1] = 1;
	g_optab[10].args[0][0] = 1;
	g_optab[10].args[0][1] = 1;
	g_optab[10].args[0][2] = 1;
	g_optab[12].args[0][0] = 1;
	g_optab[13].args[0][0] = 1;
	g_optab[13].args[0][1] = 1;
}

static void	init_args_3(void)
{
	g_optab[3].args[0][0] = 1;
	g_optab[4].args[0][0] = 1;
	g_optab[5].args[0][0] = 1;
	g_optab[6].args[0][0] = 1;
	g_optab[7].args[0][0] = 1;
	g_optab[9].args[0][0] = 1;
	g_optab[10].args[0][0] = 1;
	g_optab[10].args[0][1] = 1;
	g_optab[13].args[0][0] = 1;
}

void		init_args(void)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i < COUNT_OP)
	{
		j = 0;
		while (j < 3)
		{
			k = 0;
			while (k < 3)
			{
				g_optab[i].args[j][k] = 0;
				k++;
			}
			j++;
		}
		i++;
	}
	init_args_1();
	init_args_2();
	init_args_3();
}
