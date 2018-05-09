/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:20:42 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/02 12:23:39 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = (int)ft_strlen(src);
	str = ft_strnew(i);
	if (str == NULL)
		return (NULL);
	str = ft_strcpy(str, src);
	return (str);
}
