/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:35:47 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/11 11:35:48 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	1 - wrong CMD_STRING
**	2 - 2 name str
**	3 - 2 comment str
**	4 - no name var
**	5 - no comment var
**	6 - no name && no comment vars
**	7 - no start quote
**	8 - no end quote
**	9 - shit after command (no comment)
**	10 - no text (comment or name vars)
**
**	11 - wrong line
**	12 - wrong LABEL_CHARS
**	13 - wrong command name
**	14 - file not exist
**	15 - wrong srgs count
**	16 - wrong 1 arg
**	17 - wrong 2 arg
**	18 - wrong 3 arg
**	19 - no this lable
**	20 - wrong filename extension
**	21 - champion name too long
**	22 - champion comment too long
**	23 - there are no commands
*/

void	part_1(int error)
{
	if (error == 1)
		ft_putendl_fd("ERROR: wrong CMD_STRING", 2);
	if (error == 2)
		ft_putendl_fd("ERROR: 2 name str", 2);
	if (error == 3)
		ft_putendl_fd("ERROR: 2 comment str", 2);
	if (error == 4)
		ft_putendl_fd("ERROR: no name var", 2);
	if (error == 5)
		ft_putendl_fd("ERROR: no comment var", 2);
	if (error == 6)
		ft_putendl_fd("ERROR: no name && no comment vars", 2);
	if (error == 7)
		ft_putendl_fd("ERROR: no start quote", 2);
	if (error == 8)
		ft_putendl_fd("ERROR: no end quote", 2);
	if (error == 9)
		ft_putendl_fd("ERROR: shit after command (no comment)", 2);
	if (error == 10)
		ft_putendl_fd("ERROR: no text (comment or name vars)", 2);
}

void	part_2(int error)
{
	if (error == 11)
		ft_putendl_fd("ERROR: wrong line", 2);
	if (error == 12)
		ft_putendl_fd("ERROR: wrong LABEL_CHARS", 2);
	if (error == 13)
		ft_putendl_fd("ERROR: wrong command name", 2);
	if (error == 14)
		ft_putendl_fd("ERROR: file not exist", 2);
	if (error == 15)
		ft_putendl_fd("ERROR: wrong srgs count", 2);
	if (error == 16)
		ft_putendl_fd("ERROR: wrong 1 arg", 2);
	if (error == 17)
		ft_putendl_fd("ERROR: wrong 2 arg", 2);
	if (error == 18)
		ft_putendl_fd("ERROR: wrong 3 arg", 2);
	if (error == 19)
		ft_putendl_fd("ERROR: no this lable", 2);
	if (error == 20)
		ft_putendl_fd("ERROR: wrong filename extension", 2);
	if (error == 21)
		ft_putendl_fd("ERROR: champion name too long", 2);
	if (error == 22)
		ft_putendl_fd("ERROR: champion comment too long", 2);
}

void	ft_exit(int error, t_info info)
{
	if (error >= 1 && error <= 10)
		part_1(error);
	else
		part_2(error);
	if (error == 23)
		ft_putendl_fd("ERROR: there are no commands", 2);
	if (info.line != NULL)
	{
		ft_putstr_fd("LINE: ", 2);
		ft_putnbr_fd(info.real_num, 2);
		ft_putstr_fd("\n", 2);
		ft_putendl_fd(*(info.line), 2);
		ft_strdel(info.line);
	}
	exit(0);
}
