/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:47:04 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/26 21:26:24 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_mem			*allocate_memory(t_chemp *zero)
{
	t_mem		*memory;
	int			i;

	memory = (t_mem*)malloc(sizeof(t_mem) * MEM_SIZE);
	i = 0;
	while (i < MEM_SIZE)
	{
		memory[i].byte = 0;
		memory[i].chemp = zero;//(t_chemp *)malloc(sizeof(t_chemp));
/*		memory[i].chemp->nbr[0] = 0;
		memory[i].chemp->nbr[1] = 0;
		memory[i].chemp->nbr[2] = 0;
		memory[i].chemp->nbr[3] = 0;
*/		i++;
	}
	return (memory);
}
