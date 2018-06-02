/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:48:01 by iseletsk          #+#    #+#             */
/*   Updated: 2018/06/02 12:28:44 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	s_check_flag(char *str)
{
	if (!ft_strcmp(str, "-v"))
		return (1);
	if (!ft_strcmp(str, "-dump"))
		return (2);
	if (!ft_strcmp(str, "-n"))
		return (3);
	if (!ft_strcmp(str, "-a"))
		return (4);
	return (0);
}

static void	s_init_gflag(void)
{
	int	i;

	i = -1;
	g_flag.v = 0;
	g_flag.nbr[0] = -1;
	g_flag.nbr[1] = -2;
	g_flag.nbr[2] = -3;
	g_flag.nbr[3] = -4;
	g_flag.zerro = 123;
	g_flag.a = 0;
	g_flag.dump = -1;
	g_flag.nbr_ch = 0;
	while (++i < 4)
		g_flag.r_index[i] = 0;
}

static int	s_give_nbr(char *str)
{
	int		nbr;
	int		n;
	int		i;

	nbr = ft_atoi(str);
	n = 0;
	while (!n)
	{
		i = -1;
		n = 1;
		while (++i < 4)
			if (nbr == g_flag.nbr[i])
			{
				nbr++;
				n = 0;
				break ;
			}
	}
	return (nbr);
}

static void	s_validation(void)
{
	if (g_flag.v)
	{
		g_flag.a = 0;
		g_flag.dump = 0;
	}
}

void	vm_init_flag(int ac, char **av)
{
	int	count_ch;
	int	i;

	s_init_gflag();
	count_ch = 0;
	i = 0;
	while (++i < ac)
	{
		if (!s_check_flag(av[i]))
		{
			g_flag.r_index[count_ch] = i;
			g_flag.nbr_ch++;
			count_ch++;
		}
		else if (s_check_flag(av[i]) == 1)
			g_flag.v = 1;
		else if (s_check_flag(av[i]) == 2)
			g_flag.dump = ft_atoi(av[++i]);
		else if (s_check_flag(av[i]) == 3)
			g_flag.nbr[count_ch] = s_give_nbr(av[++i]);
		else if (s_check_flag(av[i]) == 4)
			g_flag.a = 1;
	}
	s_validation();
	g_flag.zerro = s_give_nbr("0");
}
