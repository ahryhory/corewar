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
	14 - file not exist
*/

void	ft_exit(int error)
{
	printf("ERROR: %d\n", error);
	exit(0);
}
