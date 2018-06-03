/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:47:04 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/28 15:19:04 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_mem			*allocate_memory(t_chemp *zero)
{
	t_mem		*memory;
	int			i;

	memory = (t_mem*)malloc(sizeof(t_mem) * (MEM_SIZE));
	i = 0;
	while (i < MEM_SIZE)
	{
		memory[i].byte = 0;
		memory[i].chemp = zero;
		memory[i].light = 0;
		memory[i].proc = 0;
		i++;
	}
	return (memory);
}
