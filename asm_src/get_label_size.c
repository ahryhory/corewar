/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 15:20:30 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/13 15:20:31 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				get_label_size(char *command)
{
	int			i;

	i = 0;
	while (i < COUNT_OP)
	{
		if (ft_strequ(g_optab[i].name, command))
			return (g_optab[i].lable_size);
		i++;
	}
	return (0);
}
