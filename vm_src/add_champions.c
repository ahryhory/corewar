/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:42:36 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/06/01 17:16:44 by iseletsk         ###   ########.fr       */
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

static void	get_name(t_chemp *chemp, int fd)
{
	lseek(fd, 4, 0);
	read(fd, &chemp->champ_name, PROG_NAME_LENGTH);
	lseek(fd, 8, 1);
}

static void	get_comm(t_chemp *chemp, int fd)
{
	read(fd, &chemp->champ_comm, COMMENT_LENGTH);
	lseek(fd, 4, 1);
}

void		add_champions(t_con *con, int ac, char **av, t_chemp *chemp)
{
	int			fd;
	int			i;
	int			j;
	int			file;

	file = con->dump == 0 ? 1 : 3;
	while (file < ac)
	{
		i = 0;
		fd = open(av[file], O_RDONLY);
		get_name(chemp, fd);
		get_comm(chemp, fd);
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
	close(fd);
}
