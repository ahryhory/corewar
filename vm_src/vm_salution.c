/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 10:32:23 by iseletsk          #+#    #+#             */
/*   Updated: 2018/06/03 11:00:44 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		s_check_valid(t_chemp *chemp, char **av)
{
	int			i;
	char		*str;

	i = 0;
	if (g_flag.nbr_ch > 4)
	{
		ft_putstr_fd("Error: too many champions\n", 2);
		exit(0);
	}
	while (chemp)
	{
		if (chemp->size > CHAMP_MAX_SIZE)
		{
			str = "Error: file ";
			write(2, str, ft_strlen(str));
			ft_putstr(av[g_flag.r_index[i]]);
			str = " has too large a code\n";
			write(2, str, ft_strlen(str));
			exit(0);
		}
		chemp = chemp->next;
		i++;
	}
}

static void		s_hello(t_chemp *chemp)
{
	char		*str;

	str = "Player ";
	write(1, str, ft_strlen(str));
	ft_putnbr(vm_give_fbyte(chemp->nbr));
	str = ", weighing ";
	write(1, str, ft_strlen(str));
	ft_putnbr(chemp->size);
	str = " bytes, \"";
	write(1, str, ft_strlen(str));
	write(1, chemp->champ_name, ft_strlen(chemp->champ_name));
	write(1, " (\"", 3);
	write(1, chemp->champ_comm, ft_strlen(chemp->champ_comm));
	ft_putendl("\") !");
}

void			vm_salution(t_con con, char **av)
{
	t_chemp		*chemp;

	chemp = con.chemp->next;
	if (!chemp)
	{
		usage_vm();
		exit(0);
	}
	s_check_valid(chemp, av);
	while (chemp)
	{
		s_hello(chemp);
		chemp = chemp->next;
	}
}
