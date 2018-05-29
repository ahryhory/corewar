/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:06:25 by iseletsk          #+#    #+#             */
/*   Updated: 2018/04/08 20:21:31 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			s_create_elem(t_data **sdata, int fd, char *str)
{
	int	i;
	int	count;
	int	len;

	i = -1;
	count = 0;
	*sdata = malloc(sizeof(t_data));
	while (!((*sdata)->i = 0) && str[++i])
		if (str[i] == '\n' || str[i + 1] == 0)
			count++;
	(*sdata)->fd = fd;
	(*sdata)->box = malloc(sizeof(char *) * (count + 1));
	i = -1;
	while (++i < count && !(len = 0))
	{
		while (str[len] && str[len] != '\n')
			len++;
		((*sdata)->box)[i] = ft_strsub(str, 0, len);
		while (len--)
			str++;
		str++;
	}
	((*sdata)->box)[i] = 0;
	(*sdata)->right = 0;
	(*sdata)->left = 0;
}

static t_data		*s_go_to_fd(t_data **sdata, int fd, char *str, int i)
{
	if ((*sdata)->fd == fd)
	{
		if (str)
		{
			while ((*sdata)->box[i])
				ft_strdel(&((*sdata)->box[i++]));
			free(((*sdata)->box));
			free(*sdata);
			s_create_elem(sdata, fd, str);
		}
		return (*sdata);
	}
	if ((*sdata)->fd < fd)
	{
		if (!(*sdata)->right)
			s_create_elem(&((*sdata)->right), fd, str);
		return (s_go_to_fd(&((*sdata)->right), fd, str, 0));
	}
	else
	{
		if (!(*sdata)->left)
			s_create_elem(&((*sdata)->left), fd, str);
		return (s_go_to_fd(&((*sdata)->left), fd, str, 0));
	}
}

static char			*s_strcat(char *dest, char *buf)
{
	char	*str;
	size_t	len[2];
	char	*start;
	char	*dstart;

	len[0] = 0;
	len[1] = ft_strlen(buf);
	if (dest)
		len[0] = ft_strlen(dest);
	str = malloc(sizeof(char) * (len[0] + len[1] + 1));
	str[len[0] + len[1]] = 0;
	start = str;
	dstart = dest;
	if (dest)
		while (*dest)
			*str++ = *dest++;
	ft_strdel(&dstart);
	while (*buf)
		*str++ = *buf++;
	return (start);
}

static char			*s_get_line(char *str, int fd)
{
	static t_data	*sdata;
	t_data			*data;
	char			*cpy;

	if (sdata == 0 && str)
		s_create_elem(&sdata, fd, str);
	if (sdata)
		data = s_go_to_fd(&sdata, fd, str, 0);
	else
		return (0);
	if (data->box == 0)
		return (0);
	if (data->box[data->i])
	{
		cpy = ft_strdup(data->box[data->i]);
		ft_strdel(&(data->box[data->i++]));
		return (cpy);
	}
	return (0);
}

int					get_next_line(int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*str;
	char	*box;

	str = 0;
	if (fd < 0 || read(fd, buf, 0) < 0 || !line)
		return (-1);
	*line = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		str = s_strcat(str, buf);
	}
	if ((box = s_get_line(str, fd)))
	{
		*line = ft_strdup(box);
		ft_strdel(&box);
	}
	ft_strdel(&str);
	if (*line == 0 && (*line = ft_strdup("\0")))
		return (0);
	return (1);
}
