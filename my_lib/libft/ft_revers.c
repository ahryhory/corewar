/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:53:27 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/23 14:34:25 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revers(char *str)
{
	char	buf;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str) - 1;
	while (j < i)
	{
		buf = str[i];
		str[i--] = str[j];
		str[j++] = buf;
	}
	return (str);
}
