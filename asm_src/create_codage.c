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

static void		write_bits(char *arg, char **codage, int begin)
{
	if (arg[0] == 'r')
		(*codage)[begin + 1] = '1';
	else if (arg[0] == '%')
		(*codage)[begin] = '1';
	else
	{
		(*codage)[begin] = '1';
		(*codage)[begin + 1] = '1';
	}
}

static int		if_bit(int i)
{
	if (i == 0 || i == 4)
		return (8);
	if (i == 1 || i == 5)
		return (4);
	if (i == 2 || i == 6)
		return (2);
	if (i == 3 || i == 7)
		return (1);
	return (0);
}

static char		*bits_to_hex(char **codage)
{
	int			byte_a;
	int			byte_b;
	char		*b_a;
	char		*b_b;
	int			i;

	byte_a = 0;
	byte_b = 0;
	i = 0;
	while ((*codage)[i])
	{
		if (i < 4 && (*codage)[i] == '1')
			byte_a += if_bit(i);
		if (i >= 4 && (*codage)[i] == '1')
			byte_b += if_bit(i);
		i++;
	}
	b_a = ft_itoa_base(byte_a, 16);
	b_b = ft_itoa_base(byte_b, 16);
	ft_strdel(codage);
	*codage = ft_strjoin(b_a, b_b);
	ft_strdel(&b_a);
	ft_strdel(&b_b);
	return (*codage);
}

char			*create_codage(t_commands *curr)
{
	int			i;
	char		*codage;

	i = 0;
	while (i < COUNT_OP)
	{
		if (ft_strequ(g_optab[i].name, curr->command))
			break ;
		i++;
	}
	if (g_optab[i].cod_octal != 1)
		return (NULL);
	codage = ft_strdup("00000000");
	if (curr->arg_1)
		write_bits(curr->arg_1, &codage, 0);
	if (curr->arg_2)
		write_bits(curr->arg_2, &codage, 2);
	if (curr->arg_3)
		write_bits(curr->arg_3, &codage, 4);
	return (bits_to_hex(&codage));
}
