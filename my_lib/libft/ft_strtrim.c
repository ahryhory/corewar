/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 22:10:40 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/27 12:37:33 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;

	if (!s)
		return (0);
	s = ft_skip_whtsp((char *)s);
	i = ft_strlen((char *)s) - 1;
	if (i == -1)
	{
		if (!(str = ft_strnew(0)))
			return (0);
		return (str);
	}
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	if (!(str = ft_strnew(i + 1)))
		return (0);
	ft_strncpy(str, s, i + 1);
	return (str);
}
