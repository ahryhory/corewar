/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:28:10 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/02 12:18:47 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*psr;
	unsigned char	*pds;

	psr = (unsigned char*)src;
	pds = (unsigned char*)dst;
	while (n--)
		if ((*pds++ = *psr++) == (unsigned char)c)
			return ((void *)pds);
	return (NULL);
}
