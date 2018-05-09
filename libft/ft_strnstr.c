/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:59:39 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/02 15:44:15 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstk, const char *ndle, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (!(*ndle))
		return ((char *)hstk);
	while (hstk[i] && i <= len)
	{
		while (hstk[i] == ndle[j] && i <= len)
		{
			i++;
			j++;
			if (!(ndle[j]) && i <= len)
				return ((char *)&hstk[i - j]);
			if (hstk[i] != ndle[j] && i <= len)
			{
				i -= j;
				j = 0;
				break ;
			}
		}
		i++;
	}
	return (NULL);
}
