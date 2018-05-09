/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:59:25 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/16 12:25:29 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(uintmax_t num, int base)
{
	int		count;

	count = 1;
	while (num / base != 0)
	{
		count++;
		num /= base;
	}
	return (count);
}

char		*ft_itoa_base(uintmax_t num, int base)
{
	char			*numstr;
	int				remainder;
	int				i;

	if (num == 0)
		return (ft_strdup("0"));
	i = count_num(num, base);
	numstr = (char *)malloc(sizeof(char) * (i + 1));
	numstr[i] = '\0';
	while (i >= 0)
	{
		remainder = num % base;
		if (remainder <= 9)
			numstr[--i] = remainder + '0';
		else
			numstr[--i] = remainder - 10 + 'a';
		num /= base;
	}
	return (numstr);
}
