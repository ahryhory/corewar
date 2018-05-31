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
	// check_line(info);
	// if ((*line)[0] != COMMENT_CHAR)
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
		{
			
			size += list->size;
		}
		list = list->next;
	}
	data->head.prog_size = size;
}

int					is_all_quotes(char *begin, char *line)
{
	int				i;
	int				count;

	i = 0;
	count = 0;
	if (ft_strnequ(line, begin, ft_strlen(begin)))
	{
		while (line[i])
		{
			if (line[i] == '"')
				count++;
			i++;
		}
		if (count == 2)
			return (1);
		else
			return (0);
	}
	else
	{
		while (line[i])
		{
			if (line[i] == '"')
				count++;
			i++;
		}
		if (count == 1)
			return (1);
		else
			return (0);
	}
}

t_data				parse(char *file, t_info info)
{
	int				fd;
	int				count;
	int				real_count;
	int				gnl;
	char			*line;
	char			*trim;
	char			*join;
	char			**split;
	t_data			data;

	data.command = NULL;
	info.line = NULL;
	if (!(file[ft_strlen(file) - 2] == '.' && file[ft_strlen(file) - 1] == 's'))
		ft_exit(20, info);
	fd = open(file, O_RDWR);
	if (fd < 0)
		ft_exit(14, info);
	count = 0;
	real_count = 0;
	gnl = 0;
	while ((gnl = ft_get_next_line(fd, &line)))
	{
		trim = ft_strtrim(line);
		ft_strdel(&line);
		line = ft_strdup(trim);
		ft_strdel(&trim);
		if (line && line[0] == COMMENT_CHAR)
		{
			ft_strdel(&line);
			continue ;
		}
		if (ft_strnequ(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		{
			trim = ft_strtrim(line);
			while (!is_all_quotes(NAME_CMD_STRING, trim))
			{
				ft_strdel(&line);
				if (!ft_get_next_line(fd, &line))
					ft_exit(8, info);
				join = ft_strjoin(trim, line);
				ft_strdel(&trim);
				trim = ft_strtrim(join);
				ft_strdel(&join);
			}
			ft_strdel(&line);
			line = ft_strdup(trim);
			ft_strdel(&trim);
		}
		else if (ft_strnequ(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		{
			trim = ft_strtrim(line);
			while (!is_all_quotes(COMMENT_CMD_STRING, trim))
			{
				ft_strdel(&line);
				if (!ft_get_next_line(fd, &line))
					ft_exit(8, info);
				if (ft_strlen(line) == 0)
					join = ft_strjoin(trim, "\n");
				else
					join = ft_strjoin(trim, "\n");
				ft_strdel(&trim);
				trim = ft_strdup(join);
				ft_strdel(&join);
				join = ft_strjoin(trim, line);
				ft_strdel(&trim);
				trim = ft_strdup(join);
				// trim = ft_strtrim(join);
				ft_strdel(&join);
			}
			ft_strdel(&line);
			line = ft_strdup(trim);
			ft_strdel(&trim);
		}
		else
		{
			split = ft_strsplit(line, '#');
			trim = ft_strtrim(split[0]);
			// printf("%s\n", trim);
			if (split)
				ft_split_del(&split);
			if (trim && trim[ft_strlen(trim) - 1] == ':')
			{
				ft_strdel(&line);
				while ((gnl = ft_get_next_line(fd, &line)))
				{
					split = ft_strsplit(line, '#');
					join = ft_strtrim(split[0]);
					if (split)
						ft_split_del(&split);
					ft_strdel(&line);
					if (join && join[ft_strlen(join) - 1] == ':')
					{
						// line = ft_strjoin(trim, " del this");
						// ft_strdel(&trim);
						// printf("TRIM %s\n", trim);
						count = processing(&trim, real_count, count, &data);
						ft_strdel(&trim);
						trim = ft_strdup(join);
						ft_strdel(&join);
					}
					else if (join != NULL)
					{
						line = ft_strjoin(trim, join);
						ft_strdel(&join);
						break ;
					}
					else
						ft_strdel(&join);
				}
				if (gnl <= 0)
				{
					// printf("TrIM %s\n", trim);
					count = processing(&trim, real_count, count, &data);
				}
			}
			if (trim)
			{
				// count = processing(&trim, real_count, count, &data);
				ft_strdel(&trim);
			}
		}
		real_count++;
		if (line && !ft_strequ(line, "") && check_curr_line(line))
			count = processing(&line, real_count, count, &data);
		ft_strdel(&line);
	}
	add_size(&data);
	close(fd);
	// system("leaks asm");
	return (data);
}
