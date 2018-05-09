/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:34:59 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/04 15:11:36 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	div;
	long int	nm;
	int			size;

	size = 1;
	div = 10;
	nm = (long int)n;
	if (nm < 0)
	{
		ft_putchar_fd('-', fd);
		nm *= -1;
	}
	while (nm / div != 0)
	{
		div *= 10;
		size++;
	}
	while (size--)
	{
		div /= 10;
		ft_putchar_fd((char)(nm / div + '0'), fd);
		nm %= div;
	}
}
