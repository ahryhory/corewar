/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_check_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:31:20 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:08:58 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	s_helpa(t_par *data)
{
	char	*sbox;

	sbox = ft_strdup(data->flag);
	if (!sbox)
		sbox = ft_strnew(0);
	ft_strdel(&(data->flag));
	data->flag = ft_strjoin("-", sbox);
	ft_strdel(&sbox);
}

int			ftp_check_width(char **str, va_list *ap, t_par *data)
{
	int		var;
	int		count;

	count = 0;
	if (**str == '*')
	{
		var = va_arg(*ap, int);
		if (var < 0 && (var *= -1))
			s_helpa(data);
		data->width = var;
		(*str)++;
		count++;
	}
	else if (ft_isdigit(**str))
	{
		var = ft_atoi(*str);
		(*str) += ft_coundig(var);
		data->width = var;
		count += ft_coundig(var);
	}
	return (count);
}
