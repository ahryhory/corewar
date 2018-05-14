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
*/

void	ft_exit(int error, t_info info)
{
	if (info.line != NULL)
	{
		printf("ERROR: %d\nLINE: %d\n%s\n", error, info.real_num, *(info.line));
		ft_strdel(info.line);
	}
	system("leaks asm");
	exit(0);
}
