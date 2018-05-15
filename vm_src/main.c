/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:40:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/15 12:40:17 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				main(int ac, char **av)
{	
	t_memory	*memory;
	int			i;

	if (ac == 1)
		exit(1);
	memory = allocate_memory();
	add_champions(&memory, ac, av);
	i = 0;
	while (i < MEM_SIZE)
	{
		printf("%d ", memory[i].byte);
		i++;
	}
	return (0);
}
