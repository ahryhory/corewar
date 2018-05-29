/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_strj_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:22:16 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:10:02 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void		s_helpa_flag_minus(char **rbox, char *str, t_par data)
{
	char	*anti_leaks;

	ft_memset(*rbox, ' ', data.width - ft_strlen(str));
	anti_leaks = ft_strdup(*rbox);
	ft_strdel(rbox);
	*rbox = ft_strjoin(str, anti_leaks);
	ft_strdel(&anti_leaks);
	ft_strdel(&str);
}

static void		s_helpa_flag_none(char **rbox, char *str, t_par data)
{
	char	*anti_leaks;
	char	c;

	c = ' ';
	if (ft_count_c(data.flag, '0'))
		c = '0';
	ft_memset(*rbox, c, data.width - ft_strlen(str));
	anti_leaks = ft_strdup(*rbox);
	ft_strdel(rbox);
	*rbox = ft_strjoin(anti_leaks, str);
	ft_strdel(&anti_leaks);
	ft_strdel(&str);
}

static int		s_del(char *box)
{
	ft_strdel(&box);
	return (1);
}

char			*ftp_strj_str(t_par data, t_str box)
{
	char		*rbox;
	char		*str;

	str = ft_strdup(box.str);
	if (data.precesion >= 0 && data.precesion < (int)ft_strlen(str))
	{
		ft_strdel(&str);
		str = ft_strnew(data.precesion);
		ft_memcpy(str, box.str, data.precesion);
	}
	if ((s_del(box.str) && data.width >= 0 && data.width > (int)ft_strlen(str)))
	{
		rbox = ft_strnew(data.width - ft_strlen(str));
		if (!ft_count_c(data.flag, '-'))
		{
			s_helpa_flag_none(&rbox, str, data);
		}
		else if (ft_count_c(data.flag, '-'))
			s_helpa_flag_minus(&rbox, str, data);
	}
	else
		return (str);
	return (rbox);
}
