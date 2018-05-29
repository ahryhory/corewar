/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:42:36 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/29 12:31:23 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	calc_begin(int ac, int file, t_con *con)
{
	int		size;
	int		cast;

	cast = con->dump == 0 ? 0 : 2;
	size = MEM_SIZE / (ac - cast - 1);
	if (ac - cast > 2)
		return ((file - cast - 1) * size);
	return (0);
}

void		add_champions(t_con *con, int ac, char **av, t_chemp *chemp)
{
	int			line;
	int			fd;
	int			i;
	int			j;
	int			file;

	file = con->dump == 0 ? 1 : 3;
	//printf("file %d \n", file);
	while (file < ac)
	{
		fd = open(av[file], O_RDONLY);
		i = 0;
		while (read(fd, &line, 1))
		{
			// if (i > PROG_NAME_LENGTH + 7 && i <= PROG_NAME_LENGTH + 11	)
			// 	printf("%d\n", line);
			if (i == PROG_NAME_LENGTH + COMMENT_LENGTH + 15)
				break ;
			i++;
		}
		j = calc_begin(ac, file, con);
		i = j;
		while (read(fd, &((con->mem)[j].byte), 1) > 0)
		{
			((con->mem)[j]).chemp = chemp;
			if (j++ == i)
				vm_add_proces(con, j - 1, (con->dump == 0 ? -file : -file + 2));
		}
		chemp = chemp->next;
		file++;
	}
}
