/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:52:56 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/21 22:55:04 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_index(int index, int step)
{
	int		final_index;
	int		i;

	final_index = index + step;
	while (final_index > MEM_SIZE)
		final_index -= MEM_SIZE;
	while (final_index < 0)
		final_index += MEM_SIZE;
	return (final_index);
}
