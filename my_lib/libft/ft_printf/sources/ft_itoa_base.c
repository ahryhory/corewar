/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 21:46:25 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:06:41 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	s_count_base(intmax_t nbr, int bs)
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

char		*ft_itoa_base(intmax_t nbr, int bs)
{
	int		count;
	char	*str;
	char	*start;
	int		n;

	n = 0;
	if (nbr < 0 && bs == 10)
		n = 1;
	count = s_count_base(nbr, bs);
	str = malloc(sizeof(char) * (count + 1 + n));
	start = str;
	if (!nbr)
		*str++ = 48;
	if (nbr < 0 && (*str++ = -(nbr % bs < 9 ? nbr % bs - 48 : nbr % bs - 55)))
		nbr /= -bs;
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
