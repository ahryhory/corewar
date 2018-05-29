/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_hendl_uxonbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:45:00 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:09:32 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	s_to_lower(char *rbox)
{
	while (*rbox)
	{
		if (*rbox >= 65 && *rbox <= 90)
			*rbox += 32;
		rbox++;
	}
}

static char	*s_data_cast(t_par data, va_list *ap, char conv)
{
	unsigned long long	var;
	char				*rbox;

	if (data.cast)
	{
		if (!ft_strcmp(data.cast, "l") || !ft_strcmp(data.cast, "z"))
			var = va_arg(*ap, unsigned long long);
		else if (!ft_strcmp(data.cast, "ll") || !ft_strcmp(data.cast, "j"))
			var = va_arg(*ap, unsigned long long);
		else if (!ft_strcmp(data.cast, "h"))
			var = (unsigned short)va_arg(*ap, unsigned int);
		else if (!ft_strcmp(data.cast, "hh"))
			var = (unsigned char)va_arg(*ap, unsigned int);
	}
	if ((conv == 'u' || conv == 'U'))
		rbox = ft_itoa_base_u(var, 10);
	if (conv == 'x' || conv == 'X')
	{
		rbox = ft_itoa_base_u(var, 16);
		if (conv == 'x')
			s_to_lower(rbox);
	}
	if (conv == 'o' || conv == 'O')
		rbox = ft_itoa_base_u(var, 8);
	return (rbox);
}

static void	s_make_changes(t_par data, char **rbox, char conv)
{
	char	*box;

	if (conv == 'u')
		return ;
	if (ft_count_c(data.flag, '#') && (conv == 'x' || conv == 'X') &&
			ft_strcmp(*rbox, "0"))
	{
		box = ft_strdup(*rbox);
		ft_strdel(rbox);
		if (conv == 'x')
			*rbox = ft_strjoin("0x", box);
		else
			*rbox = ft_strjoin("0X", box);
		ft_strdel(&box);
	}
	if (ft_count_c(data.flag, '#') && (conv == 'o' || conv == 'O'))
	{
		box = ft_strdup(*rbox);
		ft_strdel(rbox);
		*rbox = ft_strjoin("0", box);
		ft_strdel(&box);
	}
}

static int	s_kastil(t_par data, char **rbox, char c)
{
	if (data.precesion <= 1 && !ft_strcmp(*rbox, "0") && (c == 'o' || c == 'O')
			&& ft_count_c(data.flag, '#'))
	{
		ft_strdel(rbox);
		*rbox = ft_strdup("0");
		return (0);
	}
	if (data.precesion == 0 && !ft_strcmp(*rbox, "0"))
	{
		ft_strdel(rbox);
		*rbox = ft_strnew(0);
		return (0);
	}
	return (1);
}

char		*ftp_hendl_uxonbr(t_par *data, va_list *ap, char conv)
{
	char	*rbox;

	if (!data->cast || conv == 'U' || conv == 'O')
	{
		if (conv == 'u')
			rbox = ft_itoa_base_u(va_arg(*ap, unsigned int), 10);
		if (conv == 'U')
			rbox = ft_itoa_base_u(va_arg(*ap, unsigned long), 10);
		if (conv == 'x' || conv == 'X')
		{
			rbox = ft_itoa_base_u(va_arg(*ap, unsigned int), 16);
			if (conv == 'x')
				s_to_lower(rbox);
		}
		if (conv == 'o')
			rbox = ft_itoa_base_u(va_arg(*ap, unsigned int), 8);
		if (conv == 'O')
			rbox = ft_itoa_base_u(va_arg(*ap, unsigned long), 8);
	}
	else
		rbox = s_data_cast(*data, ap, conv);
	if (s_kastil(*data, &rbox, conv))
		s_make_changes(*data, &rbox, conv);
	ftp_hendl_xnbr(data, &rbox, conv);
	return (rbox);
}
