/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:06:42 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/05 15:33:55 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	sub = ft_strnew(len);
	if (sub == NULL)
		return (NULL);
	while (i < (int)len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
