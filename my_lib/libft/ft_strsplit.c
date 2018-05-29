/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:55:58 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 22:08:13 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	**ft_strsplit(char const *s, char c)
{
	char			**carr;
	size_t			n;
	const char		*sbox;
	char			**begin;

	if (!(sbox = s))
		return (0);
	n = ft_count_word(s, c);
	if (!(carr = (char **)malloc(sizeof(*carr) * (n + 1))))
		return (0);
	s = sbox;
	begin = carr;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		sbox = s;
		n = 0;
		while (*s && *s++ != c)
			n++;
		if (n)
			*carr++ = ft_strsub(sbox, 0, n);
	}
	*carr = 0;
	return (begin);
}
