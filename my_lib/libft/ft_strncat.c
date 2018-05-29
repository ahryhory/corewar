/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:55:05 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/24 18:00:33 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict dest, const char *restrict src, size_t n)
{
	char	*sbox;

	sbox = dest;
	while (*dest)
		dest++;
	while (*src && n != 0)
	{
		*dest++ = *src++;
		n--;
	}
	*dest = 0;
	return (sbox);
}
