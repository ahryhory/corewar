/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:37:36 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/11 14:37:37 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_text(char **p_line, t_info info, int comment)
{
	char	*line;
	char	*trim_line;

	line = *p_line;
	trim_line = ft_strtrim(line + 1);
	if (trim_line[0] == '\"' && !comment)
	{
		ft_strdel(p_line);
		ft_strdel(&trim_line);
		ft_exit(10, info);
	}
	ft_strdel(&trim_line);
}

int			check_quotes(char *line, t_info info, int comment)
{
	int		i;

	if (line[0] != '\"')
	{
		ft_strdel(&line);
		ft_exit(7, info);
	}
	check_text(&line, info, comment);
	i = 1;
	while (line[i])
	{
		if (line[i] == '\"' && line[i - 1] != '\\')
			break ;
		i++;
	}
	if (line[i] == '\0')
	{
		ft_strdel(&line);
		ft_exit(8, info);
	}
	return (i + 1);
}
