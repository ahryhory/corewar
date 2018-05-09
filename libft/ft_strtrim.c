/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:55:22 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/02 12:26:49 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	st;
	int				len;

	st = 0;
	if (s == NULL)
		return (NULL);
	while (s[st] == ' ' || s[st] == '\n' || s[st] == '\t')
		st++;
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	len = len - st + 1;
	if (len < 0)
		len = 0;
	str = ft_strsub(s, st, (size_t)len);
	if (str == NULL)
		return (NULL);
	return (str);
}
