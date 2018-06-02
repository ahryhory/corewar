/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:49:57 by ahryhory          #+#    #+#             */
/*   Updated: 2018/02/21 17:03:14 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	masc1(unsigned int c, unsigned int mask1, unsigned char ch)
{
	unsigned char	o1;
	unsigned char	o2;

	o1 = ((c >> 6) << 27) >> 27;
	o2 = (c << 26) >> 26;
	ch = (mask1 >> 8) | o1;
	write(1, &ch, 1);
	ch = ((mask1 << 24) >> 24) | o2;
	write(1, &ch, 1);
}

static void	masc2(unsigned int c, unsigned int mask2, unsigned char ch)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;

	o1 = ((c >> 12) << 28) >> 28;
	o2 = ((c >> 6) << 26) >> 26;
	o3 = (c << 26) >> 26;
	ch = (mask2 >> 16) | o1;
	write(1, &ch, 1);
	ch = ((mask2 << 16) >> 24) | o2;
	write(1, &ch, 1);
	ch = ((mask2 << 24) >> 24) | o3;
	write(1, &ch, 1);
}

static void	masc3(unsigned int c, unsigned int mask3, unsigned char ch)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;

	o1 = ((c >> 18) << 29) >> 29;
	o2 = ((c >> 12) << 26) >> 26;
	o3 = ((c >> 6) << 26) >> 26;
	o4 = (c << 26) >> 26;
	ch = (mask3 >> 24) | o1;
	write(1, &ch, 1);
	ch = ((mask3 << 8) >> 24) | o2;
	write(1, &ch, 1);
	ch = ((mask3 << 16) >> 24) | o3;
	write(1, &ch, 1);
	ch = ((mask3 << 24) >> 24) | o4;
	write(1, &ch, 1);
}

int			ft_putwchar(unsigned int c)
{
	int				size;
	unsigned char	ch;

	ch = '\0';
	size = get_count_bytes(c);
	if (size == 1)
	{
		ch = (char)c;
		write(1, &ch, 1);
		return (1);
	}
	else if (size == 2)
	{
		masc1(c, 49280, ch);
		return (2);
	}
	else if (size == 3)
	{
		masc2(c, 14712960, ch);
		return (3);
	}
	else
		masc3(c, 4034953344, ch);
	return (4);
}
