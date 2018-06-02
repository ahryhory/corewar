/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_vm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 10:46:12 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/02 10:46:13 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	usage_vm(void)
{
	ft_putstr("Usage: ./corewar [-n N] [-v | [-a] [-dump N]]");
	ft_putendl(" <champion1.cor> <...>");
	ft_putendl("-a      : Prints output from \"aff\" (Default is to hide it)");
	ft_putendl("-v      : Ncurses output mode");
	ft_putendl("-dump N : Dumps memory after N cycles then exits");
	ft_putendl("-n N    : Sets the number(N) of the next player");
}
