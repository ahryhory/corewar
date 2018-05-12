/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:38:36 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/10 16:38:37 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	int	count_al(int fd, int *oct, int *line)
{
	if (*line == 8)
	{
		write(fd, "\n", 1);
		*line = 0;
		*oct = 0;
		return (2);
	}
	if (*line != 8 && *oct == 4)
	{
		if (*line != 7)
			write(fd, " ", 1);
		*oct = 0;
		(*line)++;
		return (1);
	}
	return (0);
}

static	void	write_name(int fd, t_data data, int *oct, int *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < PROG_NAME_LENGTH)
	{
		if (count_al(fd, oct, line))
			continue ;
		if (i < ft_strlen(data.head.prog_name))
		{
			tmp = ft_itoa_base(data.head.prog_name[i], 16);
			write(fd, tmp, 2);
			free(tmp);
		}
		else
			write(fd, "00", 2);
		(*oct) += 2;
		i++;
	}
}

static	void	write_size(int fd, t_data data, int *oct, int *line)
{
	char	*tmp;
	char	bytes[10];

	write(fd, " 0000 0000 ", 11);
	cpy_in_4b(data, bytes);
	write(fd, bytes, 9);
	*oct = 4;
	*line = 5;
}

static	void	write_comm(int fd, t_data data, int *oct, int *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < COMMENT_LENGTH)
	{
		if (count_al(fd, oct, line))
			continue ;
		if (i < ft_strlen(data.head.comment))
		{
			tmp = ft_itoa_base(data.head.comment[i], 16);
			write(fd, tmp, 2);
			free(tmp);
		}
		else
			write(fd, "00", 2);
		(*oct) += 2;
		i++;
	}
	write(fd, " 0000 0000", 10);
	*line = 0;
	*oct = 0;
}

void			write_header(int fd, t_data data, int *oct, int *line)
{
	write(fd, "00ea 83f3", 9);
	write_name(fd, data, oct, line);
	write_size(fd, data, oct, line);
	write_comm(fd, data, oct, line);
}
