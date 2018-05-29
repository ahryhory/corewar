/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:11:44 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:06:34 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_count_c(const char *str, int c)
{
	int count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
		if (*str++ == c)
			count++;
	return (count);
}
