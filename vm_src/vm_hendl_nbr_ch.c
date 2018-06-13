/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_hendl_nbr_ch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:24:21 by iseletsk          #+#    #+#             */
/*   Updated: 2018/06/12 14:26:55 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	s_give_nbr(int i)
{
	int	j;

	g_flag.nbr[i] = 1;
	j = 0;
	while (j < 4)
	{
		if (g_flag.nbr[i] == g_flag.nbr[j] && j != i)
		{
			g_flag.nbr[i]++;
			j = 0;
			continue ;
		}
		j++;
	}
}

static void	s_print_error(void)
{
	char		salo[1];

	ft_putstr_fd("Error: flag [n N]: N can be from 1 to ", 2);
	*salo = g_flag.nbr_ch + 48;
	write(2, salo, 1);
	write(2, "\n", 1);
	exit(0);
}

void		vm_hendl_nbr_ch(void)
{
	int		i;

	i = 0;
	while (i < g_flag.nbr_ch)
	{
		if (g_flag.nbr[i] > g_flag.nbr_ch)
		{
			s_print_error();
		}
		if (!g_flag.nbr[i])
			s_give_nbr(i);
		i++;
	}
}
