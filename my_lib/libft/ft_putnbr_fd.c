/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:08:06 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/27 13:56:36 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0 && nb >= -2147483648)
	{
		ft_putchar_fd('-', fd);
		if (nb == -2147483648)
		{
			ft_putnbr_fd(-(nb / 10), fd);
			ft_putchar_fd('8', fd);
		}
		else
			ft_putnbr_fd(-(nb), fd);
	}
	else if (nb > 9 && nb <= 2147483647)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}
