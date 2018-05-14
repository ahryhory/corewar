/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:40:04 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/14 15:40:05 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				flag_a(t_data *data)
{
	t_commands		*list;

	printf("Name: %s\n", data->head.prog_name);
	printf("Comment: %s\n", data->head.comment);
	printf("Program size: %d bytes\n", data->head.prog_size);
	list = data->command;
	while (list)
	{
		if (list->label)
			printf("%d	%s:  ", list->begin, list->label);
		printf("%15s%s", " ", list->command);
		if (list->arg_1)
			printf(" %s", list->arg_1);
		if (list->arg_2)
			printf(" %s", list->arg_2);
		if (list->arg_3)
			printf(" %s", list->arg_3);
		printf("\n%d	(%d)\n", list->begin, list->size);
		printf("\n");
		list = list->next;
	}
}
