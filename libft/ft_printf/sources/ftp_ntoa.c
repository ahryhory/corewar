/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_ntoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:33:59 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:09:42 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char		*ftp_ntoa(t_par *data, char *str, va_list *ap)
{
	if (*str == 'd' || *str == 'i')
		return (ftp_hendl_dinbr(*data, ap, 'd'));
	if (*str == 'D')
		return (ftp_hendl_dinbr(*data, ap, 'D'));
	if (*str == 'u' || *str == 'x' || *str == 'o' ||
		*str == 'U' || *str == 'X' || *str == 'O')
		return (ftp_hendl_uxonbr(data, ap, *str));
	return (0);
}
