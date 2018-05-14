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

static char		*get_content_in_quotation(char *line)
{
	int			begin;
	int			end;

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

t_data				parse(char *file)
{
	int				fd;
	int				count;
	int				real_count;
	t_info			info;
	int				size;
	char			*line;
	char			*content;
	t_data			data;
	t_commands		*list;

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
		{
			info.line = &line;
			info.num = count;
			info.real_num = real_count;
			check_line(info);
			count++;
			if (ft_strnequ(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			{
				content = get_content_in_quotation(line);
				ft_strcpy(data.head.prog_name, content);
				ft_strdel(&content);
			}
			else if (ft_strnequ(line, COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)))
			{
				content = get_content_in_quotation(line);
				ft_strcpy(data.head.comment, content);
				ft_strdel(&content);
			}
			else
			{
				parse_line(line, &(data.command));
			}
		}
		ft_strdel(&line);
	}
	list = data.command;
	size = 0;
	while (list)
	{
		list->begin = size;
		//if (list->label)
			//printf("%d  |%s|:  ", list->begin, list->label);
		//printf("%15s|%s|", " ", list->command);
		//if (list->arg_1)
		//	printf(" %s", list->arg_1);
		//if (list->arg_2)
			//printf(" %s", list->arg_2);
		//if (list->arg_3)
		//	printf(" %s", list->arg_3);
		//printf("\n%d  (%d)\n", list->begin, list->size);
		size += list->size;
		//printf("\n");
		list = list->next;
	}
	data.head.prog_size = size;
	// printf("%d\n", data.head.prog_size);
	// printf("%s\n", data.head.prog_name);
	// printf("%s\n", data.head.comment);
	close(fd);
	// system("leaks asm");
	return (data);
}
