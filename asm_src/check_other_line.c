/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_other_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:23:09 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/10 16:23:10 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_other_line(t_info info)
{
	char	*trim_line;
	int		command;

	trim_line = ft_strtrim(*(info.line));
	command = check_first_patr(&trim_line, info);
	if (command != -3)
	{
		check_args(&trim_line, command, info);
	}
	ft_strdel(&trim_line);
}
