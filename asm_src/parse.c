/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:31:56 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/10 12:31:57 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_data			parse(char *file)
{
	int			fd;
	char		*line;
	t_data		data;

	fd = open(file, O_RDONLY);
	if (fd < 0)		/* HANDLE */
		exit(1);	/* THIS */
	while (ft_get_next_line(fd, &line))
	{
		
		ft_strdel(&line);
	}
	close(fd);
	// system("leaks asm");
	return (data);
}
