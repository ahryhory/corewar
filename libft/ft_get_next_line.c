/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:33:46 by ahryhory          #+#    #+#             */
/*   Updated: 2018/03/22 14:42:41 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int		ft_find_end(char **str)
{
	size_t		i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\n')
		{
			(*str)[i] = '\0';
			return (i + 1);
		}
		i++;
	}
	return (0);
}

static int		ft_reread(char **str, const int fd, int *check)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strnew(BUFF_SIZE);
	if ((*check = read(fd, tmp1, BUFF_SIZE)) < 0)
		return (-1);
	tmp2 = ft_strdup(*str);
	ft_strdel(str);
	*str = ft_strjoin(tmp2, tmp1);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	return (1);
}

static int		ft_clr(char **str, size_t mv)
{
	char	*tmp;

	tmp = ft_strdup(*str + mv);
	ft_strdel(str);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (1);
}

static int		ft_read(char **str, const int fd, char **line, int *check)
{
	size_t		mv;

	while ((mv = ft_find_end(str)) == 0)
	{
		if (ft_reread(str, fd, check) < 0)
			return (-1);
		if ((*str)[0] == '\0' && *check == 0)
		{
			ft_strdel(str);
			return (0);
		}
		if (*check == 0)
		{
			*line = ft_strdup(*str);
			ft_strdel(str);
			*str = ft_strdup("");
			return (1);
		}
	}
	*line = ft_strdup(*str);
	ft_clr(str, mv);
	return (1);
}

int				ft_get_next_line(const int fd, char **line)
{
	static char		*str;
	int				check;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (str == NULL)
	{
		str = ft_strnew(BUFF_SIZE);
		if ((check = read(fd, str, BUFF_SIZE)) < 0)
			return (-1);
	}
	if ((check = ft_read(&str, fd, line, &check)) < 0)
		return (-1);
	if (check)
		return (1);
	else
		return (0);
}
