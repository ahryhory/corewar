/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:56:33 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 22:18:26 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	l_check(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

int			ft_count_word(const char *str, char sep)
{
	int		n;

	n = (l_check(*str, sep) == 1 ? 0 : 1);
	while (*str)
		if (l_check(*str++, sep) && !(l_check(*str, sep)) && *str)
			n++;
	return (n);
}
