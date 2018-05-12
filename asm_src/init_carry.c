/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_carry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:32:46 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/12 14:32:47 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		init_carry(void)
{
	g_optab[0].carry = 0;
	g_optab[1].carry = 2;
	g_optab[2].carry = 0;
	g_optab[3].carry = 2;
	g_optab[4].carry = 2;
	g_optab[5].carry = 2;
	g_optab[6].carry = 2;
	g_optab[7].carry = 2;
	g_optab[8].carry = 0;
	g_optab[9].carry = 0;
	g_optab[10].carry = 0;
	g_optab[11].carry = 0;
	g_optab[12].carry = 2;
	g_optab[13].carry = 2;
	g_optab[14].carry = 0;
	g_optab[15].carry = 0;
}
