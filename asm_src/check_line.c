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

void			check_line(t_info info)
{
	if (info.num == 0 || info.num == 1)
		check_start_line(info);
	else
		check_other_line(info);
}
