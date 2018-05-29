/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:51:54 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/26 18:18:15 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*sbox;
	int			n;

	n = 0;
	sbox = s;
	while (*s)
	{
		if (*s == c && ++n)
			sbox = s;
		s++;
	}
	if (*s == c)
		return ((char *)s);
	if (!n)
		return (0);
	return ((char *)sbox);
}
