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

static void		parse_command(char *line, t_data *data)
{
	t_data		list;
	int			i;

	list = *data;
	while (list.command != NULL)
		list.command = list.command->next;
	list.command = (t_commands*)malloc(sizeof(t_commands));
	i = 0;
	while (line[i] && line[i] != COMMENT_CHAR)
	{
		if (line[i] == LABEL_CHAR && line[i - 1] != DIRECT_CHAR)
		{
			list.command->label = ft_strsub(line, 0, i);
			printf("%s\n", list.command->label);
		}
		i++;
	}
}

t_data			parse(char *file)
{
	int			fd;
	int			count;
	int			i;
	char		*line;
	char		*content;
	t_data		data;

	data.command = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)		/* HANDLE */
		exit(1);	/* THIS */
	count = 0;
	while (ft_get_next_line(fd, &line))
	{
		if (!ft_strequ(line, ""))
		{
			count++;
			// check_line(line, count);
			if (ft_strnequ(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			{
				content = get_content_in_quotation(line);
				i = 0;
				while (content[i])
				{
					data.head.prog_name[i] = content[i];
					i++;
				}
				ft_strdel(&content);
			}
			else if (ft_strnequ(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
			{
				content = get_content_in_quotation(line);
				i = 0;
				while (content[i])
				{
					data.head.comment[i] = content[i];
					i++;
				}
				ft_strdel(&content);
			}
			else
				parse_command(line, &data);
		}
		ft_strdel(&line);
	}
	close(fd);
	// system("leaks asm");
	return (data);
}
