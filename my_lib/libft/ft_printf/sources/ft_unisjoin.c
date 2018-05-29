/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unisjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:08:20 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:08:27 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

wchar_t		*ft_unisjoin(wchar_t *u1, wchar_t *u2)
{
	wchar_t	*rbox;
	size_t	i;
	size_t	j;

	rbox = ft_unisnew(ft_unislen(u1) + ft_unislen(u2));
	i = 0;
	j = 0;
	while (u1[i])
		rbox[j++] = u1[i++];
	i = 0;
	while (u2[i])
		rbox[j++] = u2[i++];
	return (rbox);
}
