/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_hendl_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:12:19 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:09:28 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	s_hendl_flag_precesion(char *str, va_list *ap, t_par *data)
{
	int		var;
	int		count;

	count = 0;
	if (*str++ != '.')
		return (0);
	if (!(data->precesion = 0) && *str == '*')
	{
		data->precesion = va_arg(*ap, int);
		return (2);
	}
	if (ft_isdigit(*str))
	{
		var = ft_atoi(str);
		data->precesion = var;
		return (ft_coundig(var) + 1);
	}
	return (1);
}

static void	s_create_data(t_par *data)
{
	data->cast = 0;
	data->flag = 0;
	data->width = -1;
	data->precesion = -1;
}

int			ftp_hendl_flag(char *str, va_list *ap, t_par *data)
{
	int		count;
	int		var;
	int		n;

	n = 1;
	s_create_data(data);
	count = 0;
	while (*str && *str != 's' && *str != 'c' && *str != 'd' && *str != 'i' &&
			*str != 'D' && *str != 'S' && *str != 'p' && *str != 'o' &&
			*str != 'O' && *str != 'x' && *str != 'X' && *str != 'u' &&
			*str != 'U' && *str != 'C' && *str != '%' && n)
	{
		n = 0;
		count += (var = ftp_check_main_flag(&str, data));
		n += var;
		count += (var = ftp_check_width(&str, ap, data));
		n += var;
		count += (var = s_hendl_flag_precesion(str, ap, data));
		n += var;
		str += var;
		count += (var = ftp_check_cast(&str, data));
		n += var;
	}
	return (count);
}
