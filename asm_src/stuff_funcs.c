/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:17:39 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/12 15:17:40 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	cpy_in_4b(int nbr, char w[9])
{
	char	*tmp;
	int		end_w;
	int		end_tmp;
	int		i;

	i = 0;
	nbr = (unsigned short)nbr;
	tmp = ft_itoa_base(nbr, 16);
	end_w = 7;
	end_tmp = ft_strlen(tmp) - 1;
	ft_strcpy(w, "00000000");
	while (end_tmp >= 0)
	{
		if (w[end_w] == ' ')
		{
			end_w--;
			continue ;
		}
		w[end_w] = tmp[end_tmp];
		end_tmp--;
		end_w--;
	}
	free(tmp);
}

void	cpy_in_2b(int nbr, char w[5])
{
	char	*tmp;
	int		end_w;
	int		end_tmp;
	int		i;

	i = 0;
	tmp = ft_itoa_base(nbr, 16);
	printf("%s\n", tmp);
	end_w = 3;
	end_tmp = ft_strlen(tmp) - 1;
	ft_strcpy(w, "0000");
	while (end_tmp >= 0)
	{
		if (w[end_w] == ' ')
		{
			end_w--;
			continue ;
		}
		w[end_w] = tmp[end_tmp];
		end_tmp--;
		end_w--;
	}
	free(tmp);
}

void	write_4b(int fd, int *oct, int *line, char w[9])
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 8)
	{
		if (count_al(fd, oct, line))
			continue ;
		write(fd, &w[i], 1);
		(*oct) += 1;
		i += 1;
	}
}

void	write_2b(int fd, int *oct, int *line, char w[5])
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 4)
	{
		if (count_al(fd, oct, line))
			continue ;
		write(fd, &w[i], 1);
		(*oct) += 1;
		i += 1;
	}
}

void	cpy_in_1b(int nbr, char w[3])
{
	char	*tmp;
	int		end_w;
	int		end_tmp;
	int		i;

	i = 0;
	tmp = ft_itoa_base(nbr, 16);
	end_w = 1;
	end_tmp = ft_strlen(tmp) - 1;
	ft_strcpy(w, "00");
	while (end_tmp >= 0)
	{
		if (w[end_w] == ' ')
		{
			end_w--;
			continue ;
		}
		w[end_w] = tmp[end_tmp];
		end_tmp--;
		end_w--;
	}
	free(tmp);
}

void	write_1b(int fd, int *oct, int *line, char w[3])
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 2)
	{
		if (count_al(fd, oct, line))
			continue ;
		write(fd, &w[i], 1);
		(*oct) += 1;
		i += 1;
	}
}

int		count_al(int fd, int *oct, int *line)
{
	if (*line == 8)
	{
		write(fd, "\n", 1);
		*line = 0;
		*oct = 0;
		return (2);
	}
	if (*line != 8 && *oct == 4)
	{
		if (*line != 7)
			write(fd, " ", 1);
		*oct = 0;
		(*line)++;
		return (1);
	}
	return (0);
}
