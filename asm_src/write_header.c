/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:38:36 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/27 15:15:45 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	write_name(int fd, t_data data)
{
	size_t	i;
	char	ch;

	i = 0;
	while (i < PROG_NAME_LENGTH + 4)
	{
		ch = '\0';
		if (i < PROG_NAME_LENGTH)
		{
			ch = data.head.prog_name[i];
			write(fd, &ch, 1);
		}
		else
			write(fd, &ch, 1);
		i++;
	}
}

static	void	write_size(int fd, t_data data)
{
	write_4b(fd, (unsigned int)data.head.prog_size);
}

static	void	write_comm(int fd, t_data data)
{
	size_t	i;
	char	ch;

	i = 0;
	while (i < COMMENT_LENGTH + 4)
	{
		ch = '\0';
		if (i < COMMENT_LENGTH)
		{
			ch = data.head.comment[i];
			write(fd, &ch, 1);
		}
		else
			write(fd, &ch, 1);
		i++;
	}
}

void			write_header(int fd, t_data data, int *oct, int *line)
{
	int		magic;

	magic = reverse(COREWAR_EXEC_MAGIC);
	oct = 0;
	line = 0;
	write(fd, &magic, 4);
	write_name(fd, data);
	write_size(fd, data);
	write_comm(fd, data);
}
