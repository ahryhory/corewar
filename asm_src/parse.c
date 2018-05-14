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
		size += list->size;
		list = list->next;
	}
	data->head.prog_size = size;
}

t_data				parse(char *file, t_info info)
{
	int				fd;
	int				count;
	int				real_count;
	char			*line;
	t_data			data;

	data.command = NULL;
	info.line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit(14, info);
	count = 0;
	real_count = 0;
	while (ft_get_next_line(fd, &line))
	{
		real_count++;
		if (!ft_strequ(line, "") && check_curr_line(line))
			count = processing(&line, real_count, count, &data);
		ft_strdel(&line);
	}
	add_size(&data);
	close(fd);
	return (data);
}
