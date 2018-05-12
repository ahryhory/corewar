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

static	void	write_magic(int fd)
{
	write(fd, "00ea 83f3 ", 10);
}

static	void	write_name(int fd, t_data data)
{
	// int		i;

	// i = 0;
	// while (i < PROG_NAME_LENGTH)
	// {
	// 	if (data.head.prog_name[i])
	// 		printf("%s\n", ft_itoa_base(data.head.prog_name[i], 16));
	// 	else
	// 		printf("%s\n", "0");
	// 	// write(fd, ft_itoa_base(data.head.prog_name[i], 16), 3);
	// 	i++;
	// }
}

void			write_header(int fd, t_data data)
{
	write_magic(fd);
	write_name(fd, data);
}
