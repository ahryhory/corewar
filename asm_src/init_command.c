/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 15:01:44 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/13 15:01:46 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_commands			*init_command(void)
{
	t_commands		*new;

	new = (t_commands*)malloc(sizeof(t_commands));
	new->label = NULL;
	new->command = NULL;
	new->arg_1 = NULL;
	new->arg_2 = NULL;
	new->arg_3 = NULL;
	new->begin = 0;
	new->size = 1;
	new->next = NULL;
	return (new);
}
