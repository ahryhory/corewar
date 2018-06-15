/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:02:10 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/05 16:25:42 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	write_begin(int i)
{
	char	*line;
	int		size;

	line = ft_itoa_base(i, 16);
	write(1, "0x", 2);
	size = ft_strlen(line);
	while (size++ < 4)
		write(1, "0", 1);
	write(1, line, ft_strlen(line));
	write(1, " : ", 3);
}

void		write_dump(t_mem *mem)
{
	int		i;
	char	*byte;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			write_begin(i);
		byte = ft_itoa_base(mem[i].byte, 16);
		if (ft_strlen(byte) == 1)
			write(1, "0", 1);
		write(1, byte, 2);
		ft_strdel(&byte);
		i++;
		if (i % 64 == 0)
			write(1, "\n", 1);
		else if (i != MEM_SIZE)
			write(1, " ", 1);
	}
	exit(0);
}
