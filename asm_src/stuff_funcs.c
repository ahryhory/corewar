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

void	cpy_in_4b(t_data data, char w[10])
{
	char	*tmp;
	int		end_w;
	int		end_tmp;
	int		i;

	i = 0;
	tmp = ft_itoa_base(data.head.prog_size, 16);
	end_w = 8;
	end_tmp = ft_strlen(tmp) - 1;
	ft_strcpy(w, "0000 0000");
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
