/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:48:01 by iseletsk          #+#    #+#             */
/*   Updated: 2018/06/12 14:27:16 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		s_check_flag(char *str, int i, int ac)
{
	if (!ft_strcmp(str, "-v"))
	{
		if (g_flag.nbr_ch)
			usage_vm();
		return (1);
	}
	else if (!ft_strcmp(str, "-dump"))
	{
		if (i >= ac - 2 || g_flag.nbr_ch || g_flag.dump > -1)
			usage_vm();
		return (2);
	}
	else if (!ft_strcmp(str, "-n"))
	{
		if (i >= ac - 2)
			usage_vm();
		return (3);
	}
	else if (!ft_strcmp(str, "-a"))
	{
		if (g_flag.nbr_ch || g_flag.a)
			usage_vm();
		return (4);
	}
	return (0);
}

static void		s_init_gflag(int *z)
{
	int			i;

	*z = 0;
	i = -1;
	g_flag.v = 0;
	g_flag.nbr[0] = 0;
	g_flag.nbr[1] = 0;
	g_flag.nbr[2] = 0;
	g_flag.nbr[3] = 0;
	g_flag.zerro = 0;
	g_flag.a = 0;
	g_flag.dump = -1;
	g_flag.nbr_ch = 0;
	while (++i < 4)
		g_flag.r_index[i] = 0;
}

static int		s_check_nbr(char *str, int n)
{
	int		nbr;
	char	*error;
	char	*del;
	int		i;

	error = n == 1 ? "Error: invalid number in the flag [-n N]" :
		"Error: invalid number in the flag [-dump N]";
	nbr = ft_atoi(str);
	if (ft_strcmp((del = ft_itoa(nbr)), str))
		nbr = -1;
	ft_strdel(&del);
	if (nbr < 0 || (n == 1 && (nbr > 4 || nbr < 1)))
	{
		ft_putendl_fd(error, 2);
		exit(0);
	}
	i = 0;
	while (n == 1 && i < 4)
		if (g_flag.nbr[i++] == nbr)
		{
			ft_putendl_fd("Error: flag [-n N]: duplicate player numbers", 2);
			exit(0);
		}
	return (nbr);
}

static int		s_give_nbr(char *str, int ch)
{
	int			nbr;
	int			n;
	int			i;

	nbr = s_check_nbr(str, 1);
	n = 0;
	while (!n)
	{
		i = -1;
		n = 1;
		while (++i < 4)
			if (nbr == g_flag.nbr[i] && i != ch)
			{
				nbr++;
				n = 0;
				break ;
			}
	}
	return (nbr);
}

void			vm_init_flag(int ac, char **av)
{
	int	i;

	s_init_gflag(&i);
	while (++i < ac)
	{
		if (!s_check_flag(av[i], i, ac) && ++g_flag.nbr_ch)
			g_flag.r_index[g_flag.nbr_ch - 1] = i;
		if (s_check_flag(av[i], i, ac) == 1)
			if ((g_flag.v += 1) && g_flag.nbr[g_flag.nbr_ch])
				usage_vm();
		if (s_check_flag(av[i], i, ac) == 2)
			if ((g_flag.dump = s_check_nbr(av[++i], 2)) &&
					g_flag.nbr[g_flag.nbr_ch])
				usage_vm();
		if (s_check_flag(av[i], i, ac) == 3)
		{
			if (g_flag.nbr[g_flag.nbr_ch])
				usage_vm();
			g_flag.nbr[g_flag.nbr_ch] = s_give_nbr(av[++i], g_flag.nbr_ch);
		}
		if (s_check_flag(av[i], i, ac) == 4)
			if ((g_flag.a = 1) && g_flag.nbr[g_flag.nbr_ch])
				usage_vm();
	}
	vm_validation();
}
