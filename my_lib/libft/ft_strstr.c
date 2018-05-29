/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:08:03 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/27 12:57:43 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *str2)
{
	const char	*sbox;
	int			j;
	int			k;

	if (ft_strlen((char *)str2) == 0)
		return ((char *)str);
	while (*str)
	{
		j = 0;
		k = 0;
		if (*str == str2[j])
		{
			sbox = str;
			while (str2[j])
			{
				if (*(str + j) == str2[j])
					k++;
				j++;
			}
		}
		if (k == j && (k > 0 && j > 0))
			return ((char *)(sbox));
		str++;
	}
	return (0);
}
