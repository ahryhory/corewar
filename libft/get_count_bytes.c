/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_count_bytes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:09:30 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 14:38:11 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_count_bytes(unsigned int c)
{
	char	*num_s;
	int		size;

	num_s = ft_itoa_base(c, 2);
	size = ft_strlen(num_s);
	if (size <= 7)
		size = 1;
	else if (size <= 11)
		size = 2;
	else if (size <= 16)
		size = 3;
	else
		size = 4;
	return (size);
}
