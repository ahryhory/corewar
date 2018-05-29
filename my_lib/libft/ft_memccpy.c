/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:30:23 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/27 12:56:00 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n)
	{
		*(unsigned char *)dest++ = *(unsigned char *)src++;
		n--;
		if ((*(unsigned char *)(src - 1)) == (unsigned char)c)
			return (dest);
	}
	return (0);
}
