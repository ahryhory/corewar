/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:34:52 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/26 21:46:07 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!s || !(str = ft_strnew(len)))
		return (0);
	i = 0;
	while (s[start] && i < (int)len)
		str[i++] = s[start++];
	while (i < (int)len)
		str[i++] = 0;
	str[i] = 0;
	return (str);
}
