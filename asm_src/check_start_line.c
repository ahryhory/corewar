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

void		check_start_line(char **line)
{
	char	*trim_line;
	int		index;

	trim_line = ft_strtrim(*line);
	index = check_cmd(trim_line, line);
	trim_line = next_part(trim_line, index);
	index = check_quotes(trim_line, line);
	trim_line = next_part(trim_line, index);
	check_comment(trim_line, line);
	free(trim_line);
}