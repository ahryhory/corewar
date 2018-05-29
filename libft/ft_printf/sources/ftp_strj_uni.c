/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_strj_uni.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:03:16 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:10:12 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int		s_give_size(wchar_t *ustr)
{
	int		size;
	int		i;

	i = -1;
	size = 0;
	while (ustr[++i])
		size += ft_size_uni(ustr[i]);
	return (size);
}

static void		s_helpa_flag_minus(wchar_t **rbox, wchar_t *ustr, t_par data)
{
	wchar_t	*anti_leaks;

	ft_unisset(*rbox, ' ', data.width - s_give_size(ustr));
	anti_leaks = ft_unisdup(*rbox);
	ft_memdel((void **)rbox);
	*rbox = ft_unisjoin(ustr, anti_leaks);
	ft_memdel((void **)&anti_leaks);
	ft_memdel((void **)&ustr);
}

static void		s_helpa_flag_none(wchar_t **rbox, wchar_t *ustr, t_par data)
{
	wchar_t	*anti_leaks;
	char	c;

	c = ' ';
	if (ft_count_c(data.flag, '0'))
		c = '0';
	ft_unisset(*rbox, (int)c, (data.width - s_give_size(ustr)));
	anti_leaks = ft_unisdup(*rbox);
	ft_memdel((void **)rbox);
	*rbox = ft_unisjoin(anti_leaks, ustr);
	ft_memdel((void **)&anti_leaks);
	ft_memdel((void **)&ustr);
}

wchar_t			*ftp_strj_uni(t_par data, t_str box)
{
	wchar_t	*rbox;
	wchar_t	*ustr;

	ustr = ft_unisdup(box.astr);
	if (data.precesion >= 0 && data.precesion < (int)s_give_size(ustr))
	{
		ft_memdel(((void **)&ustr));
		ustr = ft_unisnew(data.precesion);
		ft_uniscpy(ustr, box.astr, data.precesion);
	}
	if (data.width >= 0 && data.width > (int)s_give_size(ustr))
	{
		rbox = ft_unisnew(data.width - s_give_size(ustr));
		if (!ft_count_c(data.flag, '-'))
			s_helpa_flag_none(&rbox, ustr, data);
		else if (ft_count_c(data.flag, '-'))
			s_helpa_flag_minus(&rbox, ustr, data);
	}
	else
	{
		ft_memdel((void **)&box.astr);
		return (ustr);
	}
	ft_memdel((void **)&box.astr);
	return (rbox);
}
