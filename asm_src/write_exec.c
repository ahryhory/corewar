/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 13:26:48 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/13 13:26:49 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	write_codage(t_args args, unsigned char cod)
{
	if (!cod)
		return ;
	write_1b(args.fd, cod);
}

static	void	write_direct(t_args args, char *arg, int begin, t_commands *cmd)
{
	if (arg[0] == LABEL_CHAR)
	{
		while (!ft_strequ(cmd->label, arg + 1))
			cmd = cmd->next;
		if (g_optab[args.op].lable_size == 4)
			write_4b(args.fd, (unsigned int)cmd->begin - begin);
		else if (g_optab[args.op].lable_size == 2)
			write_2b(args.fd, (unsigned short)cmd->begin - begin);
	}
	else
	{
		if (g_optab[args.op].lable_size == 4)
			write_4b(args.fd, (unsigned int)ft_atoi(arg));
		else if (g_optab[args.op].lable_size == 2)
			write_2b(args.fd, (unsigned short)ft_atoi(arg));
	}
}

static	void	write_args(t_args args, char *arg, int begin, t_commands *cmd)
{
	if (!arg)
		return ;
	if (arg[0] == DIRECT_CHAR)
		write_direct(args, arg + 1, begin, cmd);
	else if (arg[0] == 'r')
		write_1b(args.fd, (unsigned char)ft_atoi(arg + 1));
	else if (ft_isdigit(arg[0]) || arg[0] == LABEL_CHAR || arg[0] == '-')
	{
		if (arg[0] == LABEL_CHAR)
		{
			while (!ft_strequ(cmd->label, arg + 1))
				cmd = cmd->next;
			write_2b(args.fd, (unsigned short)cmd->begin - begin);
		}
		else
			write_2b(args.fd, (unsigned short)ft_atoi(arg));
	}
}

void			write_exec(t_args args, t_commands *cur, t_commands *cmd)
{
	int				i;

	i = 0;
	while (ft_strcmp(cur->command, g_optab[i].name))
		i++;
	args.op = i;
	write_1b(args.fd, (unsigned char)args.op + 1);
	write_codage(args, create_codage(cur));
	write_args(args, cur->arg_1, cur->begin, cmd);
	write_args(args, cur->arg_2, cur->begin, cmd);
	write_args(args, cur->arg_3, cur->begin, cmd);
}
