/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:38:15 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/05 13:56:38 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	lsrc;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (ldst > dstsize)
		lsrc += dstsize;
	else
		lsrc += ldst;
	ldst = dstsize - ldst - 1;
	if ((int)ldst <= 0)
		ldst = 0;
	ft_strncat(dst, src, ldst);
	return (lsrc);
}
