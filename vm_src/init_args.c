/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:32:16 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/17 16:37:51 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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
	g_optab[1].args[1][0] = 1;
	g_optab[2].args[1][0] = 1;
	g_optab[2].args[1][2] = 1;
	g_optab[3].args[1][0] = 1;
	g_optab[4].args[1][0] = 1;
	g_optab[5].args[1][0] = 1;
	g_optab[5].args[1][1] = 1;
	g_optab[5].args[1][2] = 1;
	g_optab[6].args[1][0] = 1;
	g_optab[6].args[1][1] = 1;
	g_optab[6].args[1][2] = 1;
	g_optab[7].args[1][0] = 1;
	g_optab[7].args[1][1] = 1;
	g_optab[7].args[1][2] = 1;
	g_optab[9].args[1][0] = 1;
	g_optab[9].args[1][1] = 1;
	g_optab[10].args[1][0] = 1;
	g_optab[10].args[1][1] = 1;
	g_optab[10].args[1][2] = 1;
	g_optab[12].args[1][0] = 1;
	g_optab[13].args[1][0] = 1;
	g_optab[13].args[1][1] = 1;
}

static void	init_args_3(void)
{
	g_optab[3].args[2][0] = 1;
	g_optab[4].args[2][0] = 1;
	g_optab[5].args[2][0] = 1;
	g_optab[6].args[2][0] = 1;
	g_optab[7].args[2][0] = 1;
	g_optab[9].args[2][0] = 1;
	g_optab[10].args[2][0] = 1;
	g_optab[10].args[2][1] = 1;
	g_optab[13].args[2][0] = 1;
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
/*
static void	s_ws(t_optab *g_optab, int i, int j, int k)
{
	g_optab->args[0] = i;
	g_optab->args[1] = j;
	g_optab->args[2] = k;
}

static void	init_args_1(void)
{
	s_ws(&g_optab[0], 0, 1, 0);
	s_ws(&g_optab[1], 1, 1, 0);
	s_ws(&g_optab[2], 1, 1, 0);
	s_ws(&g_optab[3], 1, 1, 1);
	s_ws(&g_optab[4], 1, 1, 1);
	s_ws(&g_optab[5], 1, 1, 1);
	s_ws(&g_optab[6], 1, 1, 1);
	s_ws(&g_optab[7], 1, 1, 1);
	s_ws(&g_optab[8], 1, 0, 0);
	s_ws(&g_optab[9], 1, 1, 1);
	s_ws(&g_optab[10], 1, 1, 1);
	s_ws(&g_optab[11], 1, 0, 0);
	s_ws(&g_optab[12], 1, 1, 0);
	s_ws(&g_optab[13], 1, 1, 1);
	s_ws(&g_optab[14], 1, 0, 0);
	s_ws(&g_optab[15], 1, 0, 0);
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
			g_optab[i].args[j] = 0;
			j++;
		}
		i++;
	}
	init_args_1();
}

*/
