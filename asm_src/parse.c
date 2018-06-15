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
		parse.real_count++;
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
