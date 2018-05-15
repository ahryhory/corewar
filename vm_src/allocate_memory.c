/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:47:04 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/15 12:47:11 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_memory		*allocate_memory()
{
	t_memory	*memory;
	int			i;

	memory = (t_memory*)malloc(sizeof(t_memory) * MEM_SIZE);
	i = 0;
	while (i < MEM_SIZE)
	{
		memory[i].byte = 0;
		memory[i].champ_number = 0;
		i++;
	}
	return (memory);
}