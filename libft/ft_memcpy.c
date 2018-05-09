/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:05:57 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/02 12:19:55 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pds;
	unsigned char	*psr;

	pds = (unsigned char *)dst;
	psr = (unsigned char *)src;
	while (n--)
		*pds++ = *psr++;
	return (dst);
}
