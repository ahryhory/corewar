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
	1 - wrong CMD_STRING
	2 - 2 name str
	3 - 2 comment str
	4 - no name var
	5 - no comment var
	6 - no name && no comment vars
	7 - no start quote
	8 - no end quote
	9 - shit after command (no comment)
	10 - no text (comment or name vars)

	11 - wrong line
	12 - wrong LABEL_CHARS
	13 - wrong command name
	14 - file not exist
	15 - wrong srgs count
	16 - wrong 1 arg
	17 - wrong 2 arg
	18 - wrong 3 arg
	19 - no this lable
	20 - wrong filename extension
*/

void	part_1(int error)
{
	if (error == 1)
		printf("ERROR: %s\n", "wrong CMD_STRING");
	if (error == 2)
		printf("ERROR: %s\n", "2 name str");
	if (error == 3)
		printf("ERROR: %s\n", "2 comment str");
	if (error == 4)
		printf("ERROR: %s\n", "no name var");
	if (error == 5)
		printf("ERROR: %s\n", "no comment var");
	if (error == 6)
		printf("ERROR: %s\n", "no name && no comment vars");
	if (error == 7)
		printf("ERROR: %s\n", "no start quote");
	if (error == 8)
		printf("ERROR: %s\n", "no end quote");
	if (error == 9)
		printf("ERROR: %s\n", "shit after command (no comment)");
	if (error == 10)
		printf("ERROR: %s\n", "no text (comment or name vars)");
}

void	part_2(int error)
{
	if (error == 11)
		printf("ERROR: %s\n", "wrong line");
	if (error == 12)
		printf("ERROR: %s\n", "wrong LABEL_CHARS");
	if (error == 13)
		printf("ERROR: %s\n", "wrong command name");
	if (error == 14)
		printf("ERROR: %s\n", "file not exist");
	if (error == 15)
		printf("ERROR: %s\n", "wrong srgs count");
	if (error == 16)
		printf("ERROR: %s\n", "wrong 1 arg");
	if (error == 17)
		printf("ERROR: %s\n", "wrong 2 arg");
	if (error == 18)
		printf("ERROR: %s\n", "wrong 3 arg");
	if (error == 19)
		printf("ERROR: %s\n", "no this lable");
	if (error == 20)
		printf("ERROR: %s\n", "wrong filename extension");
}

void	ft_exit(int error, t_info info)
{
	if (error >= 1 && error <= 10)
		part_1(error);
	else
		part_2(error);
	if (info.line != NULL)
	{
		printf("LINE: %d\n%s\n", info.real_num, *(info.line));
		ft_strdel(info.line);
	}
	system("leaks asm");
	exit(0);
}
