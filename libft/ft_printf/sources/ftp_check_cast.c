/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_check_cast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:46:44 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 19:08:43 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	s_helpa(t_par *data, char *str, int i)
{
	char	*box;
	int		j;

	box = ft_strnew(ft_strlen(data->cast) + i);
	j = -1;
	while (data->cast[++j])
		box[j] = data->cast[j];
	ft_strdel(&data->cast);
	while (*str && i--)
		box[j++] = *str++;
	box[j] = 0;
	data->cast = box;
}

static void	s_cpy_to_d(t_par *data, char *str, int i)
{
	ft_strdel(&(data->cast));
	data->cast = ft_strnew(i);
	ft_strncpy(data->cast, str, i);
}

static void	s_check_valid(t_par *data)
{
	char	*tru;
	char	*str;
	int		n;
	char	*be;

	if (!(n = 0) && !data->cast)
		return ;
	str = ft_strdup(data->cast);
	be = str;
	tru = str;
	while (*str)
	{
		if (n < 1 && *str == 'l' && (n = 1))
			tru = str;
		if (n < 2 && *str == 'j' && (n = 2))
			tru = str;
		if (n < 3 && *str == 'z' && (n = 3))
			tru = str;
		str++;
	}
	if ((*tru == 'h' && tru[1] == 'h') || (*tru == 'l' && tru[1] == 'l'))
		s_cpy_to_d(data, tru, 2);
	else
		s_cpy_to_d(data, tru, 1);
	ft_strdel(&be);
}

int			ftp_check_cast(char **str, t_par *data)
{
	char	*start;
	int		i;

	start = *str;
	i = 0;
	while (**str && (**str == 'l' || **str == 'h' || **str == 'z' ||
			**str == 'j'))
	{
		(*str)++;
		i++;
	}
	if (!data->cast && i)
	{
		data->cast = ft_strnew(i);
		ft_strncpy(data->cast, start, i);
	}
	else if (data->cast && i)
		s_helpa(data, start, i);
	s_check_valid(data);
	return (i);
}
