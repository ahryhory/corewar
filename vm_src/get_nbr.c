/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:31:49 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/18 20:03:48 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned int	get_nbr(t_con *con, int index, int size)
{
	int		n1;
	int		n2;
	int		n3;
	int		n4;

	size = size > 4 ? 4 : size;
	n1 = size > 3 ? con->mem[index].byte << 24 : 0;
	n2 = size > 2 ? con->mem[get_index(index, size - 3)].byte << 16 : 0;
	n3 = size > 1 ? con->mem[get_index(index, size - 2)].byte << 8 : 0;
	n4 = con->mem[get_index(index, size - 1)].byte;
	return (n1 + n2 + n3 + n4);
}
