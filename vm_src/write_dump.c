/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:02:10 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/01 16:02:11 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_dump(t_mem *mem)
{
	int		i;
	char	*byte;

	i = 0;
	while (i < MEM_SIZE)
	{
		byte = ft_itoa_base(mem[i].byte, 16);
		if (ft_strlen(byte) == 1)
			write(1, "0", 1);
		write(1, byte, 2);
		i++;
		if (i % 64 == 0)
			write(1, "\n", 1);
		else if (i != MEM_SIZE)
			write(1, " ", 1);
	}
}