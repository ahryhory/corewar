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

static	void	write_opcode(t_args args)
{
	write(args.fd, g_optab[args.op].opcode, 2);
	*args.oct += 2;
	count_al(args.fd, args.oct, args.line);
}

static	void	write_codage(t_args args)
{
	if (!g_optab[args.op].cod_octal)
		return ;
	write(args.fd, "00", 2);
	*args.oct += 2;
	*args.line += 1;
	count_al(args.fd, args.oct, args.line);
}

static	void	write_args(t_args args, char *arg, int begin, t_commands *cmd)
{
	char	byte_1[3];
	char	byte_2[5];
	char	byte_4[9];

	printf("%s\n", arg);
	if (!arg)
		return ;
	if (arg[0] == DIRECT_CHAR)
	{
		arg++;
		if (arg[0] == LABEL_CHAR)
		{
			arg++;
			while (!ft_strequ(cmd->label, arg))
				cmd = cmd->next;
			if (g_optab[args.op].lable_size == 4)
			{
				cpy_in_4b((unsigned short)(cmd->begin - begin), byte_4);
				write_4b(args.fd, args.oct, args.line, byte_4);
			}

			else if (g_optab[args.op].lable_size == 2)
			{
				cpy_in_2b((unsigned short)(cmd->begin - begin), byte_2);
				write_2b(args.fd, args.oct, args.line, byte_2);
			}
		}
		else
		{
			if (g_optab[args.op].lable_size == 4)
			{
				cpy_in_4b((unsigned short)ft_atoi(arg), byte_4);
				write_4b(args.fd, args.oct, args.line, byte_4);
			}
			else if (g_optab[args.op].lable_size == 2)
			{
				cpy_in_2b((unsigned short)ft_atoi(arg), byte_2);
				write_2b(args.fd, args.oct, args.line, byte_2);
			}
		}
	}
	else if (arg[0] == 'r')
	{
		arg++;
		cpy_in_1b((unsigned short)ft_atoi(arg), byte_1);
		write_1b(args.fd, args.oct, args.line, byte_1);
	}
}

void			write_exec(t_args args, t_commands *cur, t_commands *cmd)
{
	int		i;

	i = 0;
	while (ft_strcmp(cur->command, g_optab[i].name))
		i++;
	args.op = i;
	count_al(args.fd, args.oct, args.line);
	write_opcode(args);
	write_codage(args);
	write_args(args, cur->arg_1, cur->begin, cmd);
	write_args(args, cur->arg_2, cur->begin, cmd);
	write_args(args, cur->arg_3, cur->begin, cmd);
	// exit(0);
}
