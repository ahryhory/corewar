/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:00:43 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/02 18:00:45 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_del(char ***str)
{
	size_t		i;
	char		**s;

	s = *str;
	i = 0;
	while (s[i])
	{
		ft_strdel(&s[i]);
		i++;
	}
	free(*str);
	*str = NULL;
}
