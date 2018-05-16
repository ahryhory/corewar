/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:42:36 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/16 15:47:56 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	calc_begin(int ac, int file)
{
	int		size;

	size = MEM_SIZE / (ac - 1);
	if (ac > 2)
		return ((file - 1) * size);
	return (0);
}

static t_proc	s_init_proc(t_con *con, int index)
{
	t_proc	*proc;

	proc = malloc(sizeof(t_proc));
	proc->r = s_inir_r();
	proc->cp = 0;
	proc->carry = 0;
	proc->cycl = 0;
	proc->live = CYCLE_TO_DIE;
	proc->index = index;
	proc->work = 0;
	proc->mem = con->mem;
	proc->next = 0;
	return (proc);
}

static void	s_add_proces(t_con *con, int index)
{
	t_proc	*proc;

	proc = con->proc;
	if (!proc)
		proc = s_init_proc(con, index);
	while (proc->next)
		proc = proc->next;
	proc = s_init_proc(con, index);
}

void		add_champions(t_con *con, int ac, char **av)
{
	int			line;
	int			fd;
	int			i;
	int			j;
	int			file;

	file = 1;
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
		// printf("%d\n", size);
		j = calc_begin(ac, file);
		i = j;
		// printf("%d\n", j);
		while (read(fd, (con->mem)[j].byte, 1) > 0)
			if (j++ == i)
				s_add_proces(con, j - 1);
		file++;
	}
}
