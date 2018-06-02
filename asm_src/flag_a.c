/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:40:04 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/14 15:40:05 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			print_info(t_data *data)
{
	ft_putstr("Name: ");
	ft_putendl(data->head.prog_name);
	ft_putstr("Comment: ");
	ft_putendl(data->head.comment);
	ft_putstr("Program size: ");
	ft_putnbr(data->head.prog_size);
	ft_putendl(" bytes");
}

static void			print_cmd_and_arg(t_commands *list)
{
	if (list->command)
	{
		ft_putstr("        ");
		ft_putstr(list->command);
	}
	if (list->arg_1)
	{
		ft_putstr(" ");
		ft_putstr(list->arg_1);
	}
	if (list->arg_2)
	{
		ft_putstr(" ");
		ft_putstr(list->arg_2);
	}
	if (list->arg_3)
	{
		ft_putstr(" ");
		ft_putstr(list->arg_3);
	}
}

void				flag_a(t_data *data)
{
	t_commands		*list;

	print_info(data);
	list = data->command;
	while (list)
	{
		if (list->label)
		{
			ft_putnbr(list->begin);
			ft_putstr("  ");
			ft_putstr(list->label);
			ft_putstr(": ");
		}
		print_cmd_and_arg(list);
		ft_putstr("\n");
		ft_putnbr(list->begin);
		ft_putstr("		(");
		ft_putnbr(list->size);
		ft_putendl(")");
		ft_putstr("\n");
		list = list->next;
	}
}
