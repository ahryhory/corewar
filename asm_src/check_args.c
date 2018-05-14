/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 17:04:26 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/13 17:04:28 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	cut_args(char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*line)[i] && (*line)[i] != COMMENT_CHAR)
		i++;
	tmp = ft_strsub(*line, 0, i);
	ft_strdel(line);
	*line = ft_strtrim(tmp);
	ft_strdel(&tmp);
}

static void	ft_args_trim(char ***p_args)
{
	char	*tmp;
	char	**args;
	int		i;

	args = *p_args;
	i = 0;
	while (args[i])
	{
		tmp = ft_strtrim(args[i]);
		ft_strdel(&(args[i]));
		args[i] = ft_strdup(tmp);
		ft_strdel(&tmp);
		i++;
	}
}

void		check_args(char **line, int command, t_info info)
{
	char	**args;
	int		err;
	int		count;

	cut_args(line);
	args = ft_strsplit(*line, SEPARATOR_CHAR);
	ft_args_trim(&args);
	ft_strdel(line);
	count = 0;
	while (args[count])
		count++;
	if (count != g_optab[command].args_number)
	{
		ft_split_del(&args);
		ft_exit(15, info);
	}
	err = 0;
	err = check_arg(args[0], command, 0);
	if (g_optab[command].args_number >= 2 && err == 0)
		err = check_arg(args[1], command, 1);
	if (g_optab[command].args_number >= 3 && err == 0)
		err = check_arg(args[2], command, 2);
	ft_split_del(&args);
	if (err != 0)
		ft_exit(err, info);
}
