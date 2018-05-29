/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_hendl_xnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:18:43 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:09:38 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ftp_hendl_xnbr(t_par *data, char **str, char conv)
{
	int		n;
	char	*can;
	char	*rbox;

	n = (ft_count_c(data->flag, '#') ? 2 : 0);
	if (((conv != 'x' && conv != 'X') || data->precesion <= 0 ||
			!ft_strcmp(*str, "0")) ||
	(data->precesion < (int)ft_strlen(*str) - n && (data->precesion = -1)))
		return ;
	can = ft_strnew(data->precesion - ft_strlen(*str) + n);
	ft_memset(can, '0', data->precesion - ft_strlen(*str) + n);
	rbox = ft_strjoin(can, &((*str)[n]));
	ft_strdel(str);
	ft_strdel(&can);
	if (n)
	{
		*str = ft_strjoin("0x", rbox);
		ft_strdel(&rbox);
	}
	else
		*str = rbox;
	data->precesion = -1;
}
