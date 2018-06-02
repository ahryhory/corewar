/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:47:17 by ybohusev          #+#    #+#             */
/*   Updated: 2018/06/01 20:47:19 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

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
