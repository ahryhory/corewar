/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:16:24 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/27 15:13:28 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			find_command_index(char *command)
{
	int				i;

	i = 0;
	while (i < COUNT_OP)
	{
		if (ft_strequ(g_optab[i].name, command))
			break ;
		i++;
	}
	return (i);
}

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
	if (g_optab[find_command_index((*new)->command)].cod_octal)
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
	ft_strdel(line);
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

void				parse_line(char *line, t_commands **command)
{
	t_commands		*new;
	char			*cmd;
	char			**split;

	new = init_command();
	split = ft_strsplit(line, COMMENT_CHAR);
	line = ft_strdup(split[0]);
	ft_split_del(&split);
	if (line && line[ft_strlen(line) - 1] == ':')
	{
		new->label = ft_strsub(line, 0, ft_strlen(line) - 1);
		add_new_to_list(command, new);
		ft_strdel(&line);
		return ;
	}
	if (!check_curr_line(&line, &new))
		return ;
	add_label(&new, line);
	cmd = add_command(&new, line);
	split = ft_strsplit(cmd, SEPARATOR_CHAR);
	ft_strdel(&cmd);
	add_args(&new, split);
	ft_split_del(&split);
	ft_strdel(&line);
	add_new_to_list(command, new);
}
