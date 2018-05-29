/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unisnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:49:42 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:08:35 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

wchar_t		*ft_unisnew(size_t len)
{
	wchar_t		*rbox;
	size_t		i;

	if (!(rbox = malloc(sizeof(wchar_t) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
		rbox[i++] = 0;
	rbox[i] = 0;
	return (rbox);
}
