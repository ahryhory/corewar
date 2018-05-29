/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_give_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 21:16:41 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:09:08 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*s_helpa_precesion(char *str, t_par *data)
{
	char	*sbox;
	int		n;

	if (data->precesion == -1)
		return (str);
	if (!ft_strcmp(str, "0"))
	{
		ft_strdel(&str);
		str = ft_strnew(0);
	}
	n = (data->precesion -= ft_strlen(str));
	if (n <= 0 && (data->precesion = -1))
		return (str);
	sbox = ft_strnew(ft_strlen(str) + n);
	ft_memset(sbox, '0', n);
	ft_strcpy(&(sbox[n]), str);
	data->precesion = -1;
	return (sbox);
}

static char	*s_helpa_width(char *str, t_par *data)
{
	char	*sbox;
	int		n;

	if (data->width == -1)
		return (str);
	if (!ft_strcmp(str, "0"))
	{
		ft_strdel(&str);
		str = ft_strnew(0);
	}
	n = (data->width -= ft_strlen(str) + 2);
	if (n <= 0 && (data->width = -1))
		return (str);
	sbox = ft_strnew(ft_strlen(str) + n);
	ft_memset(sbox, '0', n);
	ft_strcpy(&(sbox[n]), str);
	data->width = -1;
	return (sbox);
}

static void	s_del(t_par *data, int c)
{
	char	*del;
	int		i;

	if (!data->flag)
		return ;
	i = -1;
	del = data->flag;
	while (del[++i])
		if (del[i] == c)
			del[i] = '.';
}

t_str		ftp_give_p(void *adr, t_par *data)
{
	char	*str;
	t_str	rbox;
	int		i;

	str = ft_itoa_base((intmax_t)adr, 16);
	if (data->precesion == -1 && ft_count_c(data->flag, '0'))
		str = s_helpa_width(str, data);
	else
		str = s_helpa_precesion(str, data);
	s_del(data, '0');
	i = -1;
	while (str[++i])
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
	rbox.str = ft_strjoin("0x", str);
	rbox.astr = 0;
	ft_strdel(&str);
	return (rbox);
}
