/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unisdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:53:31 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:08:23 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

wchar_t		*s_dup_str_to_uni(char *str)
{
	wchar_t	*rbox;
	size_t	i;

	rbox = ft_unisnew(ft_strlen(str));
	i = 0;
	while (*str)
		rbox[i++] = (wchar_t)*str++;
	return (rbox);
}

wchar_t		*ft_unisdup(wchar_t *src)
{
	wchar_t	*rbox;
	wchar_t	*sbox;

	if (!src)
		return (s_dup_str_to_uni("(null)"));
	rbox = ft_unisnew(ft_unislen(src));
	sbox = rbox;
	while (*src)
		*rbox++ = *src++;
	return (sbox);
}
