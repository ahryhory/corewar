/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:52:13 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:07:59 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	s_write_byte(unsigned int *byte, int count)
{
	while (count--)
		write(1, &byte[count], 1);
}

void	s_initial(unsigned int *masc, unsigned int *byte, unsigned int unic,
		int size)
{
	masc[0] = 0;
	masc[1] = 49280;
	masc[2] = 14712960;
	masc[3] = 4034953344;
	byte[0] = unic;
	if (size == 2)
	{
		byte[0] = ((masc[1] << 24) >> 24) | ((unic << 26) >> 26);
		byte[1] = (masc[1] >> 8) | (((unic >> 6) << 27) >> 27);
	}
	if (size == 3)
	{
		byte[0] = ((masc[2] << 24) >> 24) | ((unic << 26) >> 26);
		byte[1] = ((masc[2] << 16) >> 24) | (((unic >> 6) << 26) >> 26);
		byte[2] = (masc[2] >> 16) | (((unic >> 12) << 28) >> 28);
	}
	if (size == 4)
	{
		byte[0] = ((masc[3] << 24) >> 24) | ((unic << 26) >> 26);
		byte[1] = ((masc[3] << 16) >> 24) | (((unic >> 6) << 26) >> 26);
		byte[2] = ((masc[3] << 8) >> 24) | (((unic >> 12) << 26) >> 26);
		byte[3] = (masc[3] >> 24) | (((unic >> 18) << 29) >> 29);
	}
}

int		ft_putunic(wchar_t unic)
{
	int				size;
	unsigned int	masc[4];
	unsigned int	byte[4];

	size = ft_size_uni((int)unic);
	s_initial(masc, byte, (int)unic, size);
	if (size == 1)
		write(1, byte, 1);
	else if (size != -1)
		s_write_byte(byte, size);
	return (size);
}
