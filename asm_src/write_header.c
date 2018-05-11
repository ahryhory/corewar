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

static	void	write_magic(int fd, t_data data, char g_buff[41])
{
	char	magic[9];
	int		i;
	int		j;

	i = 0;
	j = 0;
	magic[8] = '\0';
	// printf("%x\n", data.head.magic);
	// ft_strcpy(magic, "00ea 83f3");
	// printf("%s\n", magic);
	// while (magic[j])
	// {
	// 	if (g_buff[i] == ' ')
	// 		i++;
	// 	g_buff[i] = magic[j];
	// 	j++;
	// 	i++;
	// }
}

// static	void	write_name(int fd, t_data data)
// {
// 	int		i = 0;

// 	while (ft_isprint(data.head.prog_name[i]))
// 	{
// 		printf("%c", data.head.prog_name[i]);
// 		i++;
// 	}
// }

void	write_header(int fd, t_data data, char g_buff[41])
{
	write_magic(fd, data, g_buff);
	// write_name(fd, data);
}
