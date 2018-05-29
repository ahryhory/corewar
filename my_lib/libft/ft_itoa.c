/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:37:32 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/26 22:12:19 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	char	*sbox;
	int		m;

	if (!(str = ft_strnew(ft_coundig(n))))
		return (0);
	sbox = str;
	m = 1;
	if (n < 0)
		m = -1;
	*str++ = n % 10 * m + 48;
	while ((n /= 10) && m != 0)
		*str++ = n % 10 * m + 48;
	if (m == -1)
		*str++ = '-';
	*str = 0;
	return (ft_revers(sbox));
}
