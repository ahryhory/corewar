/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:26:39 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:07:05 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	s_count_base(uintmax_t nbr, int bs)
{
	int		count;

	count = 0;
	if (!nbr)
		count++;
	while (nbr)
	{
		nbr /= bs;
		count++;
	}
	return (count);
}

char		*ft_itoa_base_u(uintmax_t nbr, int bs)
{
	int		count;
	char	*str;
	char	*start;
	int		n;

	n = 0;
	count = s_count_base(nbr, bs);
	str = malloc(sizeof(char) * (count + 1 + n));
	start = str;
	if (!nbr)
		*str++ = 48;
	while (count-- && nbr)
	{
		*str++ = (nbr % bs > 9 ? nbr % bs + 55 : nbr % bs + 48);
		nbr /= bs;
	}
	if (n)
		*str++ = '-';
	*str = 0;
	return (ft_revers(start));
}
