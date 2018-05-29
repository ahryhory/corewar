/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:51:44 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:08:17 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

wchar_t	*ft_uniscpy(wchar_t *dest, wchar_t *src, int n)
{
	wchar_t	*rbox;

	rbox = dest;
	if (!dest)
		return (0);
	while (*src && (n >= ft_size_uni(*src)))
	{
		ft_memcpy(dest++, src++, 4);
		n -= ft_size_uni(*src);
	}
	return (rbox);
}
