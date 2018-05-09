/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:07:47 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/02 15:43:53 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (!(needle[j]))
				return ((char *)&haystack[i - j]);
			if (haystack[i] != needle[j])
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
