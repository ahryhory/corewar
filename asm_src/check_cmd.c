/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:02:59 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/11 13:03:01 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	equ_name(char *name_str, int *error, int name)
{
	if (ft_strequ(name_str, NAME_CMD_STRING))
	{
		if (name)
			*error = 2;
		return (1);
	}
	return (0);
}

static int	equ_comment(char *name_str, int *error, int comment)
{
	if (ft_strequ(name_str, COMMENT_CMD_STRING))
	{
		if (comment)
			*error = 3;
		return (1);
	}
	return (0);
}

static int	not_cmd(int name, int comment)
{
	if (!name && comment)
		return (4);
	if (!comment && name)
		return (5);
	else
		return (6);
}

static int	get_index(char *line, char **p_line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\"')
			break ;
		i++;
	}
	if (line[i] == '\0')
	{
		ft_strdel(p_line);
		ft_strdel(&line);
		ft_exit(1);
	}
	return (i);
}

int			check_cmd(char *line, char **p_line)
{
	char			*name_str;
	int				index;
	int				error;
	static int		name = 0;
	static int		comment = 0;

	error = 0;
	index = get_index(line, p_line);
	name_str = ft_strsub(line, 0, index);
	if (name_str[0] != '.')
		error = not_cmd(name, comment);
	else
	{
		name = equ_name(name_str, &error, name);
		comment = equ_comment(name_str, &error, comment);
		if (!name && !comment)
			error = 1;
	}
	ft_strdel(&name_str);
	if (error != 0)
	{
		ft_strdel(p_line);
		ft_strdel(&line);
		ft_exit(error);
	}
	return (index);
}
