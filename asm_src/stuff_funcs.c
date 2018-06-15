/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:17:39 by ybohusev          #+#    #+#             */
/*   Updated: 2018/06/15 15:27:48 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned int	reverse(unsigned int size)
{
	unsigned int a1;
	unsigned int a2;
	unsigned int a3;
	unsigned int a4;

	a1 = (size << 24);
	a2 = ((size >> 8) << 24) >> 8;
	a3 = ((size >> 16) << 24) >> 16;
	a4 = (size >> 24);
	return (a4 + a3 + a2 + a1);
}

void			write_4b(int fd, unsigned int size)
{
	unsigned char a1;
	unsigned char a2;
	unsigned char a3;
	unsigned char a4;

	a1 = (size << 24) >> 24;
	a2 = ((size >> 8) << 24) >> 24;
	a3 = ((size >> 16) << 24) >> 24;
	a4 = (size >> 24);
	write(fd, &a4, 1);
	write(fd, &a3, 1);
	write(fd, &a2, 1);
	write(fd, &a1, 1);
}

void			write_2b(int fd, unsigned short size)
{
	unsigned char a1;
	unsigned char a2;

	a1 = (size << 8) >> 8;
	a2 = (size >> 8);
	write(fd, &a2, 1);
	write(fd, &a1, 1);
}

void			write_1b(int fd, unsigned char size)
{
	write(fd, &size, 1);
}
