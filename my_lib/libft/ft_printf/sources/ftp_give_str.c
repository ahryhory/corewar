/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_give_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:24:48 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:09:13 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	s_helpa(t_par *data, intmax_t str)
{
	if (!str)
	{
		data->width--;
		data->c = 1;
		if (!ft_count_c(data->flag, '-') && !ft_count_c(data->flag, '0'))
			while (data->width-- > 0)
			{
				write(1, " ", 1);
				data->c++;
			}
		if (ft_count_c(data->flag, '0'))
			while (data->width-- > 0)
			{
				write(1, "0", 1);
				data->c++;
			}
		write(1, "\0", 1);
	}
}

t_str		ftp_give_str(char *str, va_list *ap, t_par *data)
{
	t_str	box;

	box.str = 0;
	box.astr = 0;
	if (*str == 'S' || (*str == 's' && ft_count_c(data->cast, 'l')))
		box.astr = ft_unisdup(va_arg(*ap, wchar_t *));
	else if (*str == 's')
	{
		box.str = ft_strdup(va_arg(*ap, char *));
		if (!box.str)
			box.str = ft_strdup("(null)");
	}
	else if (*str == 'C' || (*str == 'c' && ft_count_c(data->cast, 'l')))
	{
		box.astr = ft_unisnew(1);
		*(box.astr) = (wchar_t)va_arg(*ap, unsigned int);
		s_helpa(data, (intmax_t)*(box.astr));
	}
	else if (*str == 'c')
	{
		box.str = ft_strnew(1);
		*box.str = (intmax_t)va_arg(*ap, int);
		s_helpa(data, (intmax_t)*(box.str));
	}
	return (box);
}
