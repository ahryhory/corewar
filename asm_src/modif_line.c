/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:23:39 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/01 16:23:40 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_str_find_chr(const char *s, int c)
{
	int	i;

	i = (int)ft_strlen(s) + 1;
	while (i--)
		if (s[i] == (char)c)
			return (i);
	return (-1);
}

void		modif_line(char **p_line)
{
	char	*line;
	char	*tmp_1;
	char	*tmp_2;

	line = *p_line;
	if (ft_str_find_chr(line, ';') != -1)
	{
		while (*line)
		{
			if (*line == ';')
				*line = '#';
			line++;
		}
	}
	if (ft_str_find_chr(line, '%') != -1)
	{
		tmp_1 = ft_strsub(line, ft_str_find_chr(line, '%'), ft_strlen(line));
		tmp_2 = ft_strjoin(" ", tmp_1);
		ft_strdel(&tmp_1);
		tmp_1 = ft_strsub(line, 0, ft_str_find_chr(line, '%'));
		ft_strdel(p_line);
		*p_line = ft_strjoin(tmp_1, tmp_2);
		ft_strdel(&tmp_1);
		ft_strdel(&tmp_2);
	}
}