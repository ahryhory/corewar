/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:48:01 by iseletsk          #+#    #+#             */
/*   Updated: 2018/06/03 13:38:24 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		s_check_flag(char *str, int i, int ac)
{
	if (!ft_strcmp(str, "-v"))
		return (1);
	if (!ft_strcmp(str, "-dump"))
	{
		if (i >= ac - 2)
			usage_vm();
		return (2);
	}
	if (!ft_strcmp(str, "-n"))
	{
		if (i >= ac - 2)
			usage_vm();
		return (3);
	}
	if (!ft_strcmp(str, "-a"))
		return (4);
	return (0);
}

static void		s_init_gflag(void)
{
	int			i;

	i = -1;
	g_flag.v = 0;
	g_flag.nbr[0] = -1;
	g_flag.nbr[1] = -2;
	g_flag.nbr[2] = -3;
	g_flag.nbr[3] = -4;
	g_flag.zerro = 0;
	g_flag.a = 0;
	g_flag.dump = -1;
	g_flag.nbr_ch = 0;
	while (++i < 4)
		g_flag.r_index[i] = 0;
}

static int		s_give_nbr(char *str, int ch)
{
	int			nbr;
	int			n;
	int			i;

	nbr = vm_valid_nbr(str, 1);
	n = 0;
	while (!n)
	{
		i = -1;
		n = 1;
		while (++i < 4)
			if (nbr == g_flag.nbr[i] && ch != i)
			{
				nbr--;
				n = 0;
				break ;
			}
	}
	return (nbr);
}

static void		s_validation(void)
{
	if (g_flag.v)
	{
		g_flag.a = 0;
		g_flag.dump = 0;
	}
}

void			vm_init_flag(int ac, char **av)
{
	int	count_ch;
	int	i;

	s_init_gflag();
	count_ch = 0;
	i = 0;
	while (++i < ac)
	{
		if (!s_check_flag(av[i], i, ac))
		{
			g_flag.r_index[count_ch] = i;
			g_flag.nbr_ch++;
			count_ch++;
		}
		else if (s_check_flag(av[i], i, ac) == 1)
			g_flag.v = 1;
		else if (s_check_flag(av[i], i, ac) == 2)
			g_flag.dump = vm_valid_nbr(av[++i], 2);
		else if (s_check_flag(av[i], i, ac) == 3)
			g_flag.nbr[count_ch] = s_give_nbr(av[++i], count_ch);
		else if (s_check_flag(av[i], i, ac) == 4)
			g_flag.a = 1;
	}
	s_validation();
}
