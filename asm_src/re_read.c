/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 11:11:45 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/06/02 11:11:47 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		if_cmd_line(char **line, int fd, t_info info,
	char *define_cmd_string)
{
	char	*trim;
	char	*join;

	trim = ft_strtrim(*line);
	while (!is_all_quotes(define_cmd_string, trim))
	{
		ft_strdel(line);
		if (!ft_get_next_line(fd, line))
			ft_exit(8, info);
		if (ft_strlen(*line) == 0)
			join = ft_strjoin(trim, "\n");
		else
			join = ft_strjoin(trim, "\n");
		ft_strdel(&trim);
		trim = ft_strdup(join);
		ft_strdel(&join);
		join = ft_strjoin(trim, *line);
		ft_strdel(&trim);
		trim = ft_strdup(join);
		ft_strdel(&join);
	}
	ft_strdel(line);
	*line = ft_strdup(trim);
	ft_strdel(&trim);
}

int			if_label(char **join, t_parse *parse,
	t_data *data, char **trim)
{
	if (*join && (*join)[ft_strlen(*join) - 1] == LABEL_CHAR)
	{
		parse->count = processing(trim,
			parse->real_count, parse->count, data);
		ft_strdel(trim);
		*trim = ft_strdup(*join);
		ft_strdel(join);
	}
	else if (*join != NULL)
	{
		parse->line = ft_strjoin(*trim, *join);
		ft_strdel(join);
		return (1);
	}
	else
		ft_strdel(join);
	return (0);
}

void		read_while_not_command(t_parse *parse,
	t_data *data, char **trim)
{
	char	**split;
	char	*join;

	while ((parse->gnl = ft_get_next_line(parse->fd, &(parse->line))))
	{
		parse->real_count += 1;
		modif_line(&(parse->line));
		if (parse->line && parse->line[0] == COMMENT_CHAR)
		{
			ft_strdel(&(parse->line));
			continue ;
		}
		split = ft_strsplit(parse->line, COMMENT_CHAR);
		join = ft_strtrim(split[0]);
		if (split)
			ft_split_del(&split);
		ft_strdel(&(parse->line));
		if (if_label(&join, parse, data, trim))
			break ;
	}
}

void		if_command(t_parse *parse, t_data *data)
{
	char	*trim;
	char	**split;

	split = ft_strsplit(parse->line, COMMENT_CHAR);
	trim = ft_strtrim(split[0]);
	if (split)
		ft_split_del(&split);
	if (trim && trim[ft_strlen(trim) - 1] == LABEL_CHAR)
	{
		ft_strdel(&(parse->line));
		read_while_not_command(parse, data, &trim);
		if (parse->gnl <= 0)
			parse->count = processing(&trim, parse->real_count,
				parse->count, data);
	}
	if (trim)
		ft_strdel(&trim);
}

void		init_and_check(t_data *data, t_info *info,
	t_parse *parse, char *file)
{
	data->command = NULL;
	info->line = NULL;
	if (!(file[ft_strlen(file) - 2] == '.' && file[ft_strlen(file) - 1] == 's'))
		ft_exit(20, *info);
	parse->fd = open(file, O_RDWR);
	if (parse->fd < 0)
		ft_exit(14, *info);
	parse->count = 0;
	parse->real_count = 0;
	parse->gnl = 0;
	parse->line = NULL;
}
