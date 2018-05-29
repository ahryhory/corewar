/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:35:26 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/26 22:38:02 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	if (nb < 0 && nb >= -2147483648)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putnbr(-(nb / 10));
			ft_putchar('8');
		}
		else
			ft_putnbr(-(nb));
	}
	else if (nb > 9 && nb <= 2147483647)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}
