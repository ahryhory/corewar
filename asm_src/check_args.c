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

static int	check_arg(char *arg, int command, int arg_num)
{
	int		check;
	int		i;

	check = 0;
	if (g_optab[command].args[arg_num][0] && check == 0)
	{
		if (arg[0] == 'r')
		{
			check = 1;
			i = 1;
			while (arg[i])
			{
				if (!ft_isdigit(arg[i]))
					return (16 + arg_num);
				i++;
			}
			i = ft_atoi(arg + 1);
			if (i > REG_NUMBER || i <= 0)
				return (16 + arg_num);
		}
	}
	if (g_optab[command].args[arg_num][1] && check == 0)
	{
		if (arg[0] == DIRECT_CHAR)
		{
			check = 1;
			if (arg[1] != LABEL_CHAR)
			{
				i = 1;
				if (arg[i] == '-')
					i++;
				while (arg[i])
				{
					if (!ft_isdigit(arg[i]))
						return (16 + arg_num);
					i++;
				}
			}
		}
	}
	if (g_optab[command].args[arg_num][2] && check == 0)
	{
		if (arg[1] != LABEL_CHAR)
		{
			i = 0;
			if (arg[i] == '-')
				i++;
			while (arg[i])
			{
				if (!ft_isdigit(arg[i]))
					return (16 + arg_num);
				i++;
			}
		}
		check = 1;
	}
	if (check == 0)
		return (16 + arg_num);
	return (0);
}

void		check_args(char **line, int command, char **p_line)
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
		ft_strdel(p_line);
		ft_exit(15);
	}
	err = 0;
	err = check_arg(args[0], command, 0);
	if (g_optab[command].args_number >= 2 && err == 0)
		err = check_arg(args[1], command, 1);
	if (g_optab[command].args_number >= 3 && err == 0)
		err = check_arg(args[2], command, 2);
	ft_split_del(&args);
	if (err != 0)
	{
		ft_strdel(p_line);
		ft_exit(err);
	}
}
