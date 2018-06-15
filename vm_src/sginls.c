/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sginls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:14:19 by ybohusev          #+#    #+#             */
/*   Updated: 2018/06/03 13:14:20 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sigtstp(int sig)
{
	(void)sig;
	system("killall afplay");
	endwin();
	system("killall -STOP corewar");
}

void	sigint(int sig)
{
	(void)sig;
	system("killall afplay");
	endwin();
	system("killall corewar");
}
