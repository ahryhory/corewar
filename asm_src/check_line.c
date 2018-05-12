/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:19:41 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/10 12:19:42 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			check_line(char **line, int number_line)
{
	if (number_line == 0 || number_line == 1)
		check_start_line(line);
	else
		check_other_line(line);
}
