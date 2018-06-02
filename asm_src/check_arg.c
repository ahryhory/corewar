/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:25:58 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/14 13:25:59 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_arg_1(char *arg, int arg_num, int *check)
{
	int		i;

	if (arg[0] == 'r')
	{
		*check = 1;
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
	return (0);
}

static int	check_arg_2(char *arg, int arg_num, int *check)
{
	int		i;

	if (arg[0] == DIRECT_CHAR)
	{
		*check = 1;
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
	return (0);
}

static int	check_arg_3(char *arg, int arg_num, int *check)
{
	int		i;

	if (arg[0] != LABEL_CHAR)
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
	*check = 1;
	return (0);
}

int			check_arg(char *arg, int command, int arg_num)
{
	int		check;
	int		error;

	check = 0;
	error = 0;
	if (g_optab[command].args[arg_num][0] && check == 0)
		error = check_arg_1(arg, arg_num, &check);
	if (g_optab[command].args[arg_num][1] && check == 0)
		error = check_arg_2(arg, arg_num, &check);
	if (g_optab[command].args[arg_num][2] && check == 0)
		error = check_arg_3(arg, arg_num, &check);
	if (error != 0)
		return (error);
	if (check == 0)
		return (16 + arg_num);
	return (0);
}
