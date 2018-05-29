/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_strj_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:31:23 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:09:58 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*s_helpa(char *rbox, int w, char *str_n, t_par data)
{
	char	*box;
	int		i;
	int		n;

	ft_strdel(&rbox);
	i = 0;
	n = 0;
	if ((ft_count_c(data.flag, '+') && ft_count_c(data.flag, '0') &&
		data.precesion == -1) ||
		(data.precesion == -1 && *str_n == '-' && ft_count_c(data.flag, '0')))
		w--;
	rbox = ft_strnew(w - ft_strlen(str_n) + 2);
	if ((str_n[0] == '+' || str_n[0] == '-' || str_n[0] == ' ') && ++i)
		*rbox = str_n[0];
	else if ((str_n[0] == '0' && str_n[1] == 'x') && (i += 2) && (n = -2))
		ft_memcpy(rbox, "0x", 2);
	ft_memset(&(rbox[i]), '0', w - ft_strlen(str_n) + i + n);
	box = ft_strdup(rbox);
	ft_strdel(&rbox);
	rbox = ft_strjoin(box, &(str_n[i]));
	ft_strdel(&box);
	return (rbox);
}

static void	s_left(char **rbox, char *str_n)
{
	char	*box;

	box = ft_strdup(*rbox);
	ft_strdel(rbox);
	*rbox = ft_strjoin(str_n, box);
	ft_strdel(&box);
}

static void	s_right(char **rbox, char *str_n)
{
	char	*box;

	box = ft_strdup(*rbox);
	ft_strdel(rbox);
	*rbox = ft_strjoin(box, str_n);
	ft_strdel(&box);
}

static char	*s_hendl_width(char *str_n, t_par data)
{
	char	*rbox;

	rbox = ft_strdup(str_n);
	if (ft_count_c(data.flag, ' ') && ft_count_c(data.flag, '0') &&
			data.precesion < 0)
		data.width--;
	if (data.width >= (int)ft_strlen(rbox) && data.precesion < 0 &&
			ft_count_c(data.flag, '0'))
		rbox = s_helpa(rbox, data.width, str_n, data);
	else if (data.width > (int)ft_strlen(str_n))
	{
		ft_strdel(&rbox);
		rbox = ft_strnew(data.width - ft_strlen(str_n));
		ft_memset(rbox, ' ', data.width - ft_strlen(str_n));
		if (ft_count_c(data.flag, '-'))
			s_left(&rbox, str_n);
		else
			s_right(&rbox, str_n);
	}
	ft_strdel(&str_n);
	return (rbox);
}

char		*ftp_strj_nbr(t_par data, char *str_n)
{
	char	*rbox;
	int		castil;

	castil = 0;
	if (*str_n == '+' || *str_n == '-' || *str_n == ' ' || *str_n == '0')
	{
		castil++;
		if (*(str_n + 1) == 'x')
			castil++;
	}
	rbox = ft_strdup(str_n);
	if (data.precesion >= 0 && data.precesion > (int)ft_strlen(str_n) - castil)
		rbox = s_helpa(rbox, data.precesion, str_n, data);
	ft_strdel(&str_n);
	return (s_hendl_width(rbox, data));
}
