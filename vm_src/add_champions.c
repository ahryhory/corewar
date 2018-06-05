/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:42:36 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/06/05 16:39:28 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	calc_begin(int nbr, int file)
{
	int		size;

	size = MEM_SIZE / (nbr);
	return ((file) * size);
}

static void	validation(int fd)
{
	unsigned int	tmp;
	unsigned int	size;
	unsigned int	i;

	i = 0;
	read(fd, &tmp, 4);
	if (tmp != reverse(COREWAR_EXEC_MAGIC))
	{
		ft_putendl_fd("ERROR: Incorrect file extention", 2);
		exit(0);
	}
	lseek(fd, PROG_NAME_LENGTH, 1);
	lseek(fd, 4, 1);
	read(fd, &tmp, 4);
	tmp = reverse(tmp);
	size = 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4 + tmp;
	lseek(fd, 0, 0);
	while (read(fd, &tmp, 1))
		i++;
	if (i != size)
	{
		ft_putstr_fd("Error: File has a code size that differ from what ", 2);
		ft_putendl_fd("its header says", 2);
		exit(0);
	}
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

void		add_champions(t_con *con, char **av, t_chemp *chemp)
{
	int			fd;
	int			i;
	int			j;
	int			file;

	file = 0;
	while (file < 4 && g_flag.r_index[file] && !(i = 0))
	{
		i = 0;
		fd = open(av[g_flag.r_index[file]], O_RDONLY);
		validation(fd);
		get_name(chemp, fd);
		get_comm(chemp, fd);
		j = calc_begin(g_flag.nbr_ch, file);
		i = j;
		while (read(fd, &((con->mem)[j].byte), 1) > 0 && (chemp->size += 1))
		{
			((con->mem)[j]).chemp = chemp;
			if (j++ == i)
				vm_start_proc_init(con, j - 1, g_flag.nbr[file]);
		}
		chemp = chemp->next;
		file++;
		close(fd);
	}
}
