/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_check_main_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:18:24 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:08:48 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*s_helpa(char *data_flag, char *str, int i)
{
	char	*rbox;
	char	*box_cpy;

	box_cpy = ft_strnew(i);
	ft_strncpy(box_cpy, str, i);
	rbox = ft_strjoin(data_flag, box_cpy);
	ft_strdel(&data_flag);
	ft_strdel(&box_cpy);
	return (rbox);
}

int			ftp_check_main_flag(char **str, t_par *data)
{
	int		i;
	char	*start;

	start = *str;
	i = 0;
	while (**str && (**str == '#' || **str == '0' ||
			**str == ' ' || **str == '-' || **str == '+'))
	{
		i++;
		(*str)++;
	}
	if (i == 0)
		return (0);
	if (!data->flag)
	{
		data->flag = ft_strnew(i);
		ft_strncpy(data->flag, start, i);
	}
	else
		data->flag = s_helpa(data->flag, start, i);
	return (i);
}
