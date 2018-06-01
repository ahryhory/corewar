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

static char			*get_content_in_quotation(char *line)
{
	int				begin;
	int				end;

	begin = 0;
	while (line[begin])
	{
		if (line[begin] == '\"')
			break ;
		begin++;
	}
	begin++;
	end = begin + 1;
	while (line[end])
	{
		if (line[end] == '\\' && line[end + 1] == '\"')
			end += 2;
		if (line[end] == '\"')
			break ;
		end++;
	}
	return (ft_strsub(line, begin, end - begin));
}

static int			check_curr_line(char *line)
{
	char			**split;
	char			*trim;

	if (line[0] == COMMENT_CHAR)
		return (0);
	split = ft_strsplit(line, COMMENT_CHAR);
	trim = ft_strtrim(split[0]);
	ft_split_del(&split);
	if (ft_strequ(trim, ""))
	{
		ft_strdel(&trim);
		return (0);
	}
	ft_strdel(&trim);
	return (1);
}

static int			processing(char **line, int real_count, int count,
	t_data *data)
{
	t_info			info;
	char			*content;

	info.line = NULL;
	info.line = line;
	info.num = count;
	info.real_num = real_count;
	check_line(info);
	count++;
	if (ft_strnequ(*line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		content = get_content_in_quotation(*line);
		ft_strcpy(data->head.prog_name, content);
		ft_strdel(&content);
	}
	else if (ft_strnequ(*line, COMMENT_CMD_STRING,
		ft_strlen(COMMENT_CMD_STRING)))
	{
		content = get_content_in_quotation(*line);
		ft_strcpy(data->head.comment, content);
		ft_strdel(&content);
	}
	else
		parse_line(*line, &(data->command));
	return (count);
}

static void			add_size(t_data *data)
{
	t_commands		*list;
	int				size;

	list = data->command;
	size = 0;
	while (list)
	{
		list->begin = size;
		if (list->command != NULL)
			size += list->size;
		list = list->next;
	}
	data->head.prog_size = size;
}

int					is_all_quotes(char *begin, char *line)
{
	int				i;
	int				count;

	i = -1;
	count = 0;
	if (ft_strnequ(line, begin, ft_strlen(begin)))
	{
		while (line[++i])
			if (line[i] == '"')
				count++;
		if (count == 2)
			return (1);
		else
			return (0);
	}
	else
	{
		while (line[++i])
			if (line[i] == '"')
				count++;
		if (count == 1)
			return (1);
		else
			return (0);
	}
}

static void			if_cmd_line(char **line, int fd, t_info info,
	char *define_cmd_string)
{
	char			*trim;
	char			*join;

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

static int			if_label(char **join, t_parse *parse,
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

static void			read_while_not_command(t_parse *parse,
	t_data *data, char **trim)
{
	char			**split;
	char			*join;

	while ((parse->gnl = ft_get_next_line(parse->fd, &(parse->line))))
	{
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

static void			if_command(t_parse *parse, t_data *data)
{
	char			*trim;
	char			**split;

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

static void			init_and_check(t_data *data, t_info *info,
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

static void			check_and_change_input(t_parse *parse,
	t_info info, t_data *data)
{
	if (ft_strnequ(parse->line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		if_cmd_line(&(parse->line), parse->fd, info, NAME_CMD_STRING);
	else if (ft_strnequ(parse->line, COMMENT_CMD_STRING,
		ft_strlen(COMMENT_CMD_STRING)))
		if_cmd_line(&(parse->line), parse->fd, info, COMMENT_CMD_STRING);
	else
		if_command(parse, data);
	parse->real_count += 1;
}

static void			trim_line(t_parse *parse)
{
	char			*trim;

	trim = ft_strtrim(parse->line);
	ft_strdel(&(parse->line));
	parse->line = ft_strdup(trim);
	ft_strdel(&trim);
}

t_data				parse(char *file, t_info info)
{
	t_data			data;
	t_parse			parse;

	init_and_check(&data, &info, &parse, file);
	while ((parse.gnl = ft_get_next_line(parse.fd, &(parse.line))))
	{
		modif_line(&(parse.line));
		trim_line(&parse);
		if (parse.line && parse.line[0] == COMMENT_CHAR)
		{
			ft_strdel(&(parse.line));
			continue ;
		}
		check_and_change_input(&parse, info, &data);
		if (parse.line && !ft_strequ(parse.line, "") &&
			check_curr_line(parse.line))
			parse.count = processing(&(parse.line),
				parse.real_count, parse.count, &data);
		ft_strdel(&(parse.line));
	}
	add_size(&data);
	close(parse.fd);
	return (data);
}
