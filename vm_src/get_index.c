/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:52:56 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/15 21:53:10 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_index(int index, int step)
{
	int		final_index;

	final_index = index + step;
	return (final_index > MEM_SIZE ? final_index - MEM_SIZE : final_index);
}