/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_codage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 15:48:03 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/13 15:48:04 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static unsigned char		write_bits(char *arg, int b)
{
	unsigned char	a;

	if (arg && arg[0] == 'r')
	{
		a = 1;
		a = a << b & 255;
	}
	else if (arg && arg[0] == '%')
	{
		a = 2;
		a = a << b & 255;
	}
	else if (arg && (((ft_isdigit(arg[0]) || (arg[0] == '-' && arg[1] &&
		ft_isdigit(arg[1])))) || arg[0] == LABEL_CHAR))
	{
		a = 3;
		a = a << b & 255;
	}
	else
		a = 0;
	return (a);
}

unsigned char				create_codage(t_commands *cmd)
{
	int				i;
	unsigned char	arg1;
	unsigned char	arg2;
	unsigned char	arg3;
	unsigned char	cod;

	i = 0;
	while (ft_strcmp(cmd->command, g_optab[i].name))
		i++;
	if (!g_optab[i].cod_octal)
		return (0);
	arg1 = write_bits(cmd->arg_1, 6);
	arg2 = write_bits(cmd->arg_2, 4);
	arg3 = write_bits(cmd->arg_3, 2);
	cod = arg1 + arg2 + arg3;
	return (cod);
}
