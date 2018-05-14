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

void		check_other_line(char **line)
{
	char	*trim_line;
	int		command;

	trim_line = ft_strtrim(*line);
	command = check_first_patr(&trim_line, line);
	check_args(&trim_line, command, line);
	ft_strdel(&trim_line);
}
