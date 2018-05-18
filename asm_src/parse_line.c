/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:16:24 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/12 15:16:25 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			add_args(t_commands **new, char **split)
{
	int				i;
	char			*trim;

	i = 0;
	while (split[i])
	{
		trim = ft_strtrim(split[i]);
		if (trim[0] == DIRECT_CHAR)
			(*new)->size += get_label_size((*new)->command);
		else if (trim[0] == 'r')
			(*new)->size += 1;
		else
			(*new)->size += 2;
		if (i == 0)
			(*new)->arg_1 = ft_strdup(trim);
		if (i == 1)
			(*new)->arg_2 = ft_strdup(trim);
		if (i == 2)
			(*new)->arg_3 = ft_strdup(trim);
		i++;
		ft_strdel(&trim);
	}
	if (i > 1)
		(*new)->size += 1;
}

static void			add_label(t_commands **new, char *line)
{
	int				i;

	i = 0;
	while (line[i] && line[i] != COMMENT_CHAR)
	{
		if (line[i + 1] && line[i] == LABEL_CHAR && (line[i + 1] == ' ' ||
			line[i + 1] == '\t'))
		{
			(*new)->label = ft_strsub(line, 0, i);
			break ;
		}
		i++;
	}
}

static int			check_curr_line(char **line, t_commands **new)
{
	char			**split;

	if ((*line)[0] == COMMENT_CHAR)
	{
		free(*new);
		*new = NULL;
		return (0);
	}
	split = ft_strsplit(*line, COMMENT_CHAR);
	*line = ft_strtrim(split[0]);
	ft_split_del(&split);
	if (ft_strequ(*line, ""))
	{
		ft_strdel(line);
		free(*new);
		*new = NULL;
		return (0);
	}
	return (1);
}

static char			*add_command(t_commands **new, char *line)
{
	int				size;
	int				i;
	char			*cmd;
	char			*trim;
	char			**split;

	size = ft_strlen((*new)->label);
	if (size > 0)
		size++;
	cmd = ft_strsub(line, size, ft_strlen(line) - ft_strlen((*new)->label));
	trim = ft_strtrim(cmd);
	ft_strdel(&cmd);
	i = 0;
	while (trim[i])
	{
		if (trim[i] == ' ')
		{
			split = ft_strsplit(trim, ' ');
			break ;
		}
		if (trim[i] == '\t')
		{
			split = ft_strsplit(trim, '\t');
			break ;
		}
		i++;
	}
	(*new)->command = ft_strdup(split[0]);
	cmd = ft_strsub(trim, ft_strlen((*new)->command),
		ft_strlen(trim) - ft_strlen((*new)->command));
	size = 0;
	while ((*new)->command[size] && (*new)->command[size] != ':')
		size++;
	if (size < ft_strlen((*new)->command))
	{
		(*new)->label = ft_strsub((*new)->command, 0, size);
		ft_strdel(&trim);
		trim = ft_strsub((*new)->command, size + 1,
			ft_strlen((*new)->command) - (size + 1));
		ft_strdel(&(*new)->command);
		(*new)->command = ft_strdup(trim);
	}
	ft_strdel(&trim);
	ft_split_del(&split);
	return (cmd);
}

void				parse_line(char *line, t_commands **command)
{
	t_commands		*new;
	t_commands		*lst;
	char			*cmd;
	char			**split;

	new = init_command();
	if (!check_curr_line(&line, &new))
		return ;
	add_label(&new, line);
	cmd = add_command(&new, line);
	split = ft_strsplit(cmd, SEPARATOR_CHAR);
	ft_strdel(&cmd);
	add_args(&new, split);
	ft_split_del(&split);
	ft_strdel(&line);
	lst = *command;
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = new;
	}
	else
		*command = new;
}
