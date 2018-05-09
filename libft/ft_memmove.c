/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 10:47:37 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/05 16:54:46 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pds;
	unsigned char	*psr;

	pds = (unsigned char *)dst;
	psr = (unsigned char *)src;
	if (dst > src)
		while (len--)
			pds[len] = psr[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
