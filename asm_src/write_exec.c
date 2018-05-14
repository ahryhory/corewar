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
	count_al(args.fd, args.oct, args.line, 16);
	write(args.fd, g_optab[args.op].opcode, 2);
	*args.oct += 2;
	if (*args.oct == 4)
		*args.line += 1;
	count_al(args.fd, args.oct, args.line, 16);
}

static	void	write_codage(t_args args, unsigned char cod)
{
	char	*codage;

	count_al(args.fd, args.oct, args.line, 16);
	if (!cod)
		return ;
	codage = ft_itoa_base(cod, 16);
	write(args.fd, codage, 2);
	*args.oct += 2;
	if (*args.oct == 4)
		*args.line += 1;
	// *args.line += 1;
	count_al(args.fd, args.oct, args.line, 16);
}

static	void	write_args(t_args args, char *arg, int begin, t_commands *cmd)
{
	char	byte_1[3];
	char	byte_2[5];
	char	byte_4[9];

	count_al(args.fd, args.oct, args.line, 16);
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
				cpy_in_4b((unsigned int)(cmd->begin - begin), byte_4);
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
				cpy_in_4b((unsigned int)ft_atoi(arg), byte_4);
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
		cpy_in_1b(ft_atoi(arg), byte_1);
		write_1b(args.fd, args.oct, args.line, byte_1);
	}
	else if (ft_isdigit(arg[0]) || arg[0] == LABEL_CHAR || arg[0] == '-')
	{
		if (arg[0] == LABEL_CHAR)
			arg++;
		cpy_in_2b((unsigned short)ft_atoi(arg), byte_2);
		write_2b(args.fd, args.oct, args.line, byte_2);
	}
	count_al(args.fd, args.oct, args.line, 16);
}

void			write_exec(t_args args, t_commands *cur, t_commands *cmd)
{
	int				i;
	unsigned char	cod;

	i = 0;
	while (ft_strcmp(cur->command, g_optab[i].name))
		i++;
	args.op = i;
	count_al(args.fd, args.oct, args.line, 16);
	write_opcode(args);
	write_codage(args, create_codage(cur));
	write_args(args, cur->arg_1, cur->begin, cmd);
	write_args(args, cur->arg_2, cur->begin, cmd);
	write_args(args, cur->arg_3, cur->begin, cmd);
	count_al(args.fd, args.oct, args.line, 16);
}
