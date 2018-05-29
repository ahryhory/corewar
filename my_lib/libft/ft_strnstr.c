/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:28:26 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/27 14:26:54 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t n)
{
	size_t	l;

	while (!*big)
		big++;
	if (*lit)
	{
		l = ft_strlen((char *)lit);
		while (n && n-- >= l && *big)
		{
			if (ft_strncmp(big, lit, l) == 0)
				return ((char *)big);
			big++;
		}
		return (0);
	}
	return ((char *)big);
}
