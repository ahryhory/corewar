/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_hendl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:41:55 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:09:17 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	s_helpa(t_par *data, int *n)
{
	t_str	proc;

	proc.str = ft_strdup("%");
	data->precesion = -1;
	ftp_putstr_del(ftp_strj_str(*data, proc), n, *data);
}

int			ftp_hendl(const char *str, int c, va_list *ap, int *n)
{
	t_par	data;

	c += ftp_hendl_flag((char *)str, ap, &data);
	str += c;
	ftp_check_valid(&data, *str);
	if (!(data.c = 0) && *str == '%' && ++c)
		s_helpa(&data, n);
	if ((*str == 'S' || *str == 'C' || ((*str == 'c' || *str == 's') &&
			ft_count_c(data.cast, 'l'))) && ++c)
		ftp_putunis_del(ftp_strj_uni(data, ftp_give_str((char *)str, ap, &data))
				, n, data);
	if (((*str == 's' || *str == 'c') && !ft_count_c(data.cast, 'l')) && ++c)
		ftp_putstr_del(ftp_strj_str(data, ftp_give_str((char *)str, ap, &data))
				, n, data);
	if ((*str == 'd' || *str == 'D' || *str == 'i' || *str == 'o' ||
				*str == 'O' || *str == 'u' || *str == 'U' || *str == 'x' ||
				*str == 'X') && (c++ || c))
		ftp_putstr_del(ftp_strj_nbr(data, ftp_ntoa(&data, (char *)str, ap))
				, n, data);
	if (*str == 'p' && (c++ || c))
		ftp_putstr_del(ftp_strj_str(data, ftp_give_p(va_arg(*ap, void *)
						, &data)), n, data);
	ftp_clear_data(&data);
	return (c);
}
