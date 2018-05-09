/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:48:10 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/02 12:19:12 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*uc;

	uc = (unsigned char *)s;
	while (n--)
		if (*uc++ == (unsigned char)c)
			return ((void *)(uc - 1));
	return (NULL);
}
