/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:27:47 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:07:22 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		calc;
	int		var;

	va_start(ap, str);
	calc = 0;
	count = 0;
	while (*str)
	{
		if (*str == '%' && *str++)
		{
			str += (var = ftp_hendl(str, 0, &ap, &count));
			if (count == -1)
				calc = -1;
		}
		if (*str && *str != '%')
		{
			if ((var = ft_putunic((wchar_t)(*str++))) == -1)
				return (-1);
			count += var;
		}
	}
	va_end(ap);
	return (calc == -1 ? -1 : count);
}
