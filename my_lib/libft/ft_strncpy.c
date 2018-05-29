/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:03:12 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/26 17:02:35 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*sbox;

	sbox = dest;
	while (n && *src)
	{
		*dest++ = *src++;
		n--;
	}
	while (n)
	{
		*dest++ = 0;
		n--;
	}
	return (sbox);
}
