/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_patr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 14:19:12 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/01 15:53:30 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	del_and_exit(char **line1, char **line2, t_info info, int err)
{
	ft_strdel(line1);
	ft_strdel(line2);
	ft_exit(err, info);
}

static int	check_command_name(char *line, char **p_line, t_info info)
{
	int		i;
	int		check;
	char	*str;

	i = 0;
	check = 0;
	while (i < COUNT_OP)
	{
		if (ft_strequ(line, g_optab[i].name))
		{
			check = 1;
			break ;
		}
		i++;
	}
	if (!check)
		del_and_exit(&line, p_line, info, 13);
	str = ft_strsub(*p_line, ft_strlen(line), ft_strlen(*p_line));
	ft_strdel(&line);
	ft_strdel(p_line);
	*p_line = ft_strtrim(str);
	ft_strdel(&str);
	return (i);
}

static char	*cut_name(char *line, char **p_line, t_info info)
{
	int		i;
	char	*trim_line;
	char	*name;

	if (info.num)
		i = 0;
	trim_line = ft_strtrim(line);
	ft_strdel(&line);
	i = 0;
	while (trim_line[i] && trim_line[i] != ' ' && trim_line[i] != '\t')
		i++;
	if (trim_line[i] == '\0')
	{
		ft_strdel(&trim_line);
		ft_strdel(p_line);
		if (i == 0)
			return (NULL);
		else
			ft_exit(11, info);
	}
	name = ft_strsub(trim_line, 0, i);
	ft_strdel(&trim_line);
	return (name);
}

static int	check_lable(char *line, char **p_line, t_info info)
{
	int		i;
	int		command;
	char	*name;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(LABEL_CHARS, line[i]))
			del_and_exit(&line, p_line, info, 12);
		i++;
	}
	if (i == 0)
		ft_exit(12, info);
	ft_strdel(&line);
	line = ft_strsub(*p_line, i + 1, ft_strlen(*p_line));
	ft_strdel(p_line);
	*p_line = ft_strtrim(line);
	name = cut_name(line, p_line, info);
	if (name == NULL)
		return (-3);
	command = check_command_name(name, p_line, info);
	return (command);
}

int			check_first_patr(char **line, t_info info)
{
	int		i;
	char	*name;
	int		command;

	i = 0;
	while ((*line)[i] != ' ' && (*line)[i] != LABEL_CHAR &&
			(*line)[i] != '\t' && (*line)[i] != '\0')
		i++;
	if ((*line)[i] == '\0')
	{
		ft_strdel(line);
		ft_exit(11, info);
	}
	name = ft_strsub(*line, 0, i);
	if ((*line)[i] == LABEL_CHAR)
	{
		command = check_lable(name, line, info);
		if (command == -3)
			return (command);
	}
	else
		command = check_command_name(name, line, info);
	return (command);
}
