/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:42:36 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/15 14:42:37 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		add_champions(t_memory **memory, int ac, char **av)
{
	int			line;
	int			fd;
	int			i;
	int			j;
	int			

	fd = open(av[1], O_RDONLY);
	i = 0;
	j = 0;
	while (read(fd, &line, 1))
	{
		// if (i > PROG_NAME_LENGTH + 7 && i <= PROG_NAME_LENGTH + 11	)
		// 	printf("%d\n", line);
		if (i == PROG_NAME_LENGTH + COMMENT_LENGTH + 15)
			break ;
		i++;
	}
	// printf("%d\n", size);
	j = 0;
	while (read(fd, &(*memory)[j].byte, 1))
		j++;
}
