/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:33:43 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/27 14:25:51 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;

	len_dest = ft_strlen(dest);
	if (size <= len_dest)
		return (ft_strlen((char *)src) + size);
	ft_strncat(dest, src, size - len_dest - 1);
	return (len_dest + ft_strlen((char *)src));
}
