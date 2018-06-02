/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:10:43 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/06/01 20:10:49 by dmelnyk          ###   ########.fr       */
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

void		check_param(char **p_line)
{
	char	*l;
	char	*tmp_1;
	char	*tmp_2;

	if (ft_str_find_chr(l, DIRECT_CHAR) != -1)
	{
		tmp_1 = ft_strsub(l, ft_str_find_chr(l, DIRECT_CHAR), ft_strlen(l));
		tmp_2 = ft_strjoin(" ", tmp_1);
		ft_strdel(&tmp_1);
		tmp_1 = ft_strsub(l, 0, ft_str_find_chr(l, DIRECT_CHAR));
		ft_strdel(p_line);
		*p_line = ft_strjoin(tmp_1, tmp_2);
		ft_strdel(&tmp_1);
		ft_strdel(&tmp_2);
	}
}

void		modif_line(char **p_line)
{
	char	*l;

	if (ft_strnequ(*p_line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))
		|| ft_strnequ(*p_line, COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING)))
		return ;
	l = *p_line;
	if (ft_str_find_chr(l, ';') != -1)
	{
		while (*l)
		{
			if (*l == ';')
				*l = COMMENT_CHAR;
			l++;
		}
	}
	check_param(p_line);
}
