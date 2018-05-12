/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_byte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:17:49 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/10 13:17:50 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	int		open_cor(char *file)
{
	int		fd;
	char	*tmp;

	file[ft_strlen(file) - 1] = '\0';
	tmp = ft_strjoin(file, "cor");
	fd = open(tmp, O_CREAT | O_RDWR | O_TRUNC, S_IREAD | S_IWRITE);
	free(tmp);
	return (fd);
}

void			write_byte(t_data data, char *file)
{
	int		fd;
	int		oct;
	int		line;

	oct = 4;
	line = 1;
	fd = open_cor(file);
	write_header(fd, data, &oct, &line);
	close(fd);
}
