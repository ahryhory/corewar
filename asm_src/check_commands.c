/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 14:46:48 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/14 14:46:49 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_lbl(char *label, t_commands *commands)
{
	int			check;
	char		*line;
	t_info		info;
	t_commands	*head;

	check = 0;
	head = commands;
	while (commands)
	{
		if (ft_strequ(label, commands->label))
			check = 1;
		commands = commands->next;
	}
	if (!check)
	{
		line = ft_strdup(label);
		// FREE HEAD (STRUCT COMMANDS)
		info.line = &line;
		info.num = 0;
		info.real_num = 0;
		ft_exit(19, info);
	}
}

static void	cut_lable(char *arg, t_commands *head)
{
	if (arg[0] == LABEL_CHAR)
		check_lbl(arg + 1, head);
	else if (arg[1] == LABEL_CHAR)
		check_lbl(arg + 2, head);
}

void		check_commands(t_commands *commands)
{
	t_commands	*head;

	head = commands;
	while (commands)
	{
		if (commands->arg_1)
			cut_lable(commands->arg_1, head);
		if (commands->arg_2)
			cut_lable(commands->arg_2, head);
		if (commands->arg_3)
			cut_lable(commands->arg_3, head);
		commands = commands->next;
	}
}
