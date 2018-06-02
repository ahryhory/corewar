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
	int			fd;
	int			oct;
	int			line;
	t_args		args;
	t_commands	*cmd;

	oct = 4;
	line = 1;
	args.oct = &oct;
	args.line = &line;
	fd = open_cor(file);
	args.fd = fd;
	cmd = data.command;
	write_header(fd, data, args.oct, args.line);
	while (cmd)
	{
		if (cmd->command == NULL)
		{
			cmd = cmd->next;
			continue ;
		}
		write_exec(args, cmd, data.command);
		cmd = cmd->next;
	}
	close(fd);
}
