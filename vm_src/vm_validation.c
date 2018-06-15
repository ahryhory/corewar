/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:26:29 by iseletsk          #+#    #+#             */
/*   Updated: 2018/06/13 19:35:31 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_validation(void)
{
	if (g_flag.v > 1)
		ft_putendl_fd("Error: too many flag [-v]", 2);
	if (g_flag.nbr_ch > 4)
	{
		ft_putendl_fd("Error: too many champions", 2);
		exit(0);
	}
	if (g_flag.v && (g_flag.dump >= 0 || g_flag.a))
		usage_vm();
	vm_hendl_nbr_ch();
}
