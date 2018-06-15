/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_valid_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:09:29 by iseletsk          #+#    #+#             */
/*   Updated: 2018/06/03 13:38:47 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_valid_nbr(char *str, int n)
{
	char	*del;
	int		nbr;
	char	*error;

	nbr = ft_atoi(str);
	del = ft_itoa(nbr);
	error = n == 1 ? "Error: invalid number in the flag [n N]" :
		"Error: invalid number in the flag [dump N]";
	if (ft_strcmp(del, str))
	{
		ft_putendl_fd(error, 2);
		exit(0);
	}
	ft_strdel(&del);
	if (n == 1 && (nbr > 4 || nbr < 1))
		return (-1);
	return (-nbr);
}
