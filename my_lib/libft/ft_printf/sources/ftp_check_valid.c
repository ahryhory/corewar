/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_check_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 21:40:58 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:08:54 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	s_uninst_c(char **str, char c)
{
	char	*s;

	s = *str;
	if (!s)
		return ;
	while (*s)
	{
		if (*s == c)
			*s = '.';
		s++;
	}
}

void		ftp_check_valid(t_par *data, char c)
{
	if (ft_count_c(data->flag, '-'))
		s_uninst_c(&(data->flag), '0');
	if (ft_count_c(data->flag, '+'))
		s_uninst_c(&(data->flag), ' ');
	if (c == 'u')
		s_uninst_c(&(data->flag), '#');
	if (data->precesion >= 0 && c != '%' && c != 'c' && c != 'C' && c != 's'
			&& c != 'S')
		ft_replace_c(data->flag, '0', '.');
}
