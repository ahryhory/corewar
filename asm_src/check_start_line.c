/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:39:31 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/10 14:39:32 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*next_part(char *line, int index)
{
	char	*tmp;

	tmp = ft_strsub(line, index, ft_strlen(line));
	ft_strdel(&line);
	line = ft_strtrim(tmp);
	ft_strdel(&tmp);
	return (line);
}

void		check_start_line(t_info info)
{
	char	*trim_line;
	int		index;
	int		comment;

	comment = 0;
	trim_line = ft_strtrim(*(info.line));
	index = check_cmd(trim_line, info, &comment);
	trim_line = next_part(trim_line, index);
	index = check_quotes(trim_line, info, comment);
	trim_line = next_part(trim_line, index);
	check_comment(trim_line, info);
	ft_strdel(&trim_line);
}
