/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 11:21:38 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/06/02 11:21:40 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char				*get_content_in_quotation(char *line)
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
	end = begin;
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

static void			init_this_please(t_info *info, char **line, int count,
	int real_count)
{
	info->line = NULL;
	info->line = line;
	info->num = count;
	info->real_num = real_count;
	check_line(*info);
}

int					processing(char **line, int real_count, int count,
	t_data *data)
{
	t_info			info;
	char			*content;

	init_this_please(&info, line, count, real_count);
	count++;
	if (ft_strnequ(*line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		content = get_content_in_quotation(*line);
		if (ft_strlen(content) > PROG_NAME_LENGTH)
			ft_exit(21, info);
		ft_strncpy(data->head.prog_name, content, PROG_NAME_LENGTH);
		ft_strdel(&content);
	}
	else if (ft_strnequ(*line, COMMENT_CMD_STRING,
		ft_strlen(COMMENT_CMD_STRING)))
	{
		content = get_content_in_quotation(*line);
		if (ft_strlen(content) > COMMENT_LENGTH)
			ft_exit(22, info);
		ft_strncpy(data->head.comment, content, COMMENT_LENGTH);
		ft_strdel(&content);
	}
	else
		parse_line(*line, &(data->command));
	return (count);
}

void				add_size(t_data *data)
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
