/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putunis_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:31:24 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:09:54 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ftp_putunis_del(wchar_t *ustr, int *n, t_par data)
{
	size_t	i;
	int		calc;

	i = -1;
	(*n) += data.c;
	while (ustr[++i])
	{
		calc = ft_putunic(ustr[i]);
		if (calc == -1)
		{
			*n = -1;
			ft_memdel((void **)&ustr);
			return ;
		}
		*n += calc;
	}
	ft_memdel((void **)&ustr);
}
