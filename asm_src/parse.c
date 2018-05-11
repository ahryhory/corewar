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

static int		get_size(char *command)
{
	if (ft_strequ(command, "live"))
		return (4);
	if (ft_strequ(command, "ld"))
		return (4);
	if (ft_strequ(command, "st"))
		return (4);
	if (ft_strequ(command, "add"))
		return (4);
	if (ft_strequ(command, "sub"))
		return (4);
	if (ft_strequ(command, "and"))
		return (4);
	if (ft_strequ(command, "or"))
		return (4);
	if (ft_strequ(command, "xor"))
		return (4);
	if (ft_strequ(command, "zjmp"))
		return (2);
	if (ft_strequ(command, "ldi"))
		return (2);
	if (ft_strequ(command, "sti"))
		return (2);
	if (ft_strequ(command, "fork"))
		return (2);
	if (ft_strequ(command, "lld"))
		return (4);
	if (ft_strequ(command, "lldi"))
		return (2);
	if (ft_strequ(command, "lfork"))
		return (2);
	if (ft_strequ(command, "aff"))
		return (4);
	return (0);
}

static void		parse_command(char *line, t_commands **command)
{
	t_data		list;
	t_commands	*lst;
	t_commands	*new;
	int			i;
	char		*cmd;
	char		*trim;
	char		**no_com;
	char		**split;

	new = (t_commands*)malloc(sizeof(t_commands));
	new->label = NULL;
	new->command = NULL;
	new->arg_1 = NULL;
	new->arg_2 = NULL;
	new->arg_3 = NULL;
	new->begin = 0;
	new->size = 0;
	new->next = NULL;
	if (line[0] == COMMENT_CHAR)
	{
		free(new);
		new = NULL;
		return ;
	}
	no_com = ft_strsplit(line, COMMENT_CHAR);
	line = ft_strtrim(no_com[0]);
	ft_split_del(&no_com);
	if (ft_strequ(line, ""))
	{
		ft_strdel(&line);
		free(new);
		new = NULL;
		return ;
	}
	i = 0;
	while (line[i] && line[i] != COMMENT_CHAR)
	{
		if (line[i + 1] && line[i] == LABEL_CHAR && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		{
			new->label = ft_strsub(line, 0, i);
			break ;
		}
		i++;
	}
	i = ft_strlen(new->label);
	if (i > 0)
		i++;
	cmd = ft_strsub(line, i, ft_strlen(line) - ft_strlen(new->label));
	trim = ft_strtrim(cmd);
	ft_strdel(&cmd);
	split = ft_strsplit(trim, ' ');
	if (split[0])
		new->command = ft_strdup(split[0]);
	cmd = ft_strsub(trim, ft_strlen(new->command),
		ft_strlen(trim) - ft_strlen(new->command));
	ft_strdel(&trim);
	ft_split_del(&split);
	split = ft_strsplit(cmd, SEPARATOR_CHAR);
	ft_strdel(&cmd);
	new->size = 1;
	i = 0;
	while (split[i])
	{
		trim = ft_strtrim(split[i]);
		if (trim[0] == DIRECT_CHAR)
		{
			new->size += get_size(new->command);
		}
		else if (trim[0] == 'r')
			new->size += 1;
		else
			new->size += 2;
		if (i == 0)
			new->arg_1 = ft_strdup(trim);
		if (i == 1)
			new->arg_2 = ft_strdup(trim);
		if (i == 2)
			new->arg_3 = ft_strdup(trim);
		i++;
		ft_strdel(&trim);
	}
	

	if (i > 1)
		new->size += 1;
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

t_data			parse(char *file)
{
	int			fd;
	int			count;
	int			i;
	char		*line;
	char		*content;
	t_data		data;
	t_commands	*list;

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
			{
				parse_command(line, &(data.command));
			}
		}
		ft_strdel(&line);
	}
	list = data.command;
	int size = 0;
	while(list)
	{
		list->begin = size;
		if (list->label)
			printf("%d  %s:", list->begin, list->label);
		printf("%15s%s", " ", list->command);
		if (list->arg_1)
			printf(" %s", list->arg_1);
		if (list->arg_2)
			printf(" %s", list->arg_2);
		if (list->arg_3)
			printf(" %s", list->arg_3);
		printf("\n%d  (%d)\n", list->begin, list->size);
		size += list->size;
		printf("\n");
		list = list->next;
	}
	data.head.prog_size = size;
	printf("%d\n", data.head.prog_size);
	close(fd);
	// system("leaks asm");
	return (data);
}
