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

static	void	write_name(int fd, t_data data)
{
	int		i;
	char	ch;

	i = 0;
	while (i < PROG_NAME_LENGTH + 4)
	{
		ch = '\0';
		if (i < ft_strlen(data.head.prog_name))
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
	int		size;
	int		tmp;

	size = 325;
	// // tmp = size;
	// // tmp = tmp << 24;
	// // write(fd, &tmp, 1);
	// // tmp = size;
	// // tmp = (tmp >> 8) << 16;
	// // write(fd, &tmp, 1);
 // 	tmp = (tmp << 24) >> 8;
	// write(fd, &tmp, 1);
	// tmp = size;
	// tmp = tmp >> 8;
	// write(fd, &tmp, 1);
	// tmp = size;
	// tmp = (tmp >> 16) << 24;
	// write(fd, &tmp, 1);
	unsigned char a1 = 0;
	unsigned char a2 = 0;
	unsigned char a3 = 0;
	unsigned char a4 = 0;
	a1 = (size << 24) >> 24;
	a2 = ((size >> 8) << 24) >> 24;
	a3 = ((size >> 16) << 24) >> 24;
	a4 = (size >> 24);
	// write(fd, &a4, 1);
	// write(fd, &a3, 1);
	write(fd, &a2, 1);
	write(fd, &a1, 1);
}

// static	void	write_comm(int fd, t_data data, int *oct, int *line)
// {
// 	int		i;
// 	char	*tmp;

// 	i = 0;
// 	while (i < COMMENT_LENGTH)
// 	{
// 		if (count_al(fd, oct, line, 8))
// 			continue ;
// 		if (i < ft_strlen(data.head.comment))
// 		{
// 			tmp = ft_itoa_base(data.head.comment[i], 16);
// 			write(fd, tmp, 2);
// 			free(tmp);
// 		}
// 		else
// 			write(fd, "00", 2);
// 		(*oct) += 2;
// 		i++;
// 	}
// 	write(fd, " 0000 0000", 10);
// 	*line = 0;
// 	*oct = 0;
// 	write(fd, "\n", 1);
// }

void			write_header(int fd, t_data data, int *oct, int *line)
{
	int		magic = 0xF383EA00;
	write(fd, &magic, 4);
	write_name(fd, data);
	write_size(fd, data);
	// write_comm(fd, data, oct, line);
}
