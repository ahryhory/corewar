/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 11:01:20 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/06/02 11:01:22 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*add_command(t_commands **new, char *line)
{
	int			size;
	char		*cmd;
	char		*trim;

	get_command(new, line, &trim);
	cmd = ft_strsub(trim, ft_strlen((*new)->command),
		ft_strlen(trim) - ft_strlen((*new)->command));
	size = 0;
	while ((*new)->command[size] && (*new)->command[size] != ':')
		size++;
	if (size < (int)ft_strlen((*new)->command))
	{
		(*new)->label = ft_strsub((*new)->command, 0, size);
		ft_strdel(&trim);
		trim = ft_strsub((*new)->command, size + 1,
			ft_strlen((*new)->command) - (size + 1));
		ft_strdel(&(*new)->command);
		(*new)->command = ft_strdup(trim);
	}
	ft_strdel(&trim);
	return (cmd);
}

void			get_command(t_commands **new, char *line, char **trim)
{
	int			i;
	char		*cmd;
	char		**split;

	i = ft_strlen((*new)->label);
	if (i > 0)
		i++;
	cmd = ft_strsub(line, i, ft_strlen(line) - ft_strlen((*new)->label));
	*trim = ft_strtrim(cmd);
	ft_strdel(&cmd);
	split = 0;
	i = 0;
	while ((*trim)[i])
	{
		if ((*trim)[i] == ' ')
			split = ft_strsplit(*trim, ' ');
		if ((*trim)[i] == '\t')
			split = ft_strsplit(*trim, '\t');
		if ((*trim)[i] == ' ' || (*trim)[i] == '\t')
			break ;
		i++;
	}
	(*new)->command = ft_strdup(split[0]);
	ft_split_del(&split);
}
