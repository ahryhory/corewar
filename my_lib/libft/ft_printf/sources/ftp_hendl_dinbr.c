/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_hendl_dinbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:44:33 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:09:21 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	s_make_changes(t_par data, char **rbox)
{
	char	*box;

	box = ft_strdup(*rbox);
	ft_strdel(rbox);
	if (ft_count_c(data.flag, '+') && *box != '-')
	{
		*rbox = ft_strjoin("+", box);
		ft_strdel(&box);
	}
	else if (ft_count_c(data.flag, ' ') && *box != '-')
	{
		*rbox = ft_strjoin(" ", box);
		ft_strdel(&box);
	}
	else
	{
		*rbox = ft_strdup(box);
		ft_strdel(&box);
	}
}

static int	s_kastil(t_par data, char **str)
{
	if (data.precesion == 0 && **str == '0' && ft_count_c(data.flag, ' '))
	{
		ft_strdel(str);
		*str = ft_strdup(" ");
		return (0);
	}
	else if (data.precesion == 0 && **str == '0' && !ft_count_c(data.flag, '+'))
	{
		ft_strdel(str);
		*str = ft_strnew(0);
		return (0);
	}
	else if (data.precesion == 0 && **str == '0' && ft_count_c(data.flag, '+'))
	{
		ft_strdel(str);
		*str = ft_strdup("+");
		return (0);
	}
	return (1);
}

char		*ftp_hendl_dinbr(t_par data, va_list *ap, char c)
{
	char	*rbox;

	if (c == 'D' && ft_count_c(data.cast, 'h'))
		rbox = ft_itoa_base(va_arg(*ap, intmax_t), 10);
	else if (!data.cast && c != 'D')
		rbox = ft_itoa_base(va_arg(*ap, int), 10);
	else if (!data.cast && c == 'D')
		rbox = ft_itoa_base(va_arg(*ap, long), 10);
	else
	{
		if (!ft_strcmp(data.cast, "z"))
			rbox = ft_itoa_base(va_arg(*ap, size_t), 10);
		if (!ft_strcmp(data.cast, "j") || !ft_strcmp(data.cast, "ll"))
			rbox = ft_itoa_base(va_arg(*ap, intmax_t), 10);
		if (!ft_strcmp(data.cast, "hh"))
			rbox = ft_itoa_base((char)va_arg(*ap, int), 10);
		if (!ft_strcmp(data.cast, "l"))
			rbox = ft_itoa_base(va_arg(*ap, long), 10);
		if (!ft_strcmp(data.cast, "h"))
			rbox = ft_itoa_base((short)va_arg(*ap, int), 10);
	}
	if (s_kastil(data, &rbox))
		s_make_changes(data, &rbox);
	return (rbox);
}
