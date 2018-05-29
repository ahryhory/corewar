/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:24:14 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/24 13:18:26 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	l_lstptonull(t_list **alist)
{
	if ((*alist)->next)
		l_lstptonull(&((*alist)->next));
	free(*alist);
	*alist = 0;
}

void		ft_lstdel(t_list **alist, void (*del)(void *, size_t))
{
	t_list	*list;

	list = *alist;
	while (list)
	{
		del(list->content, list->content_size);
		list = list->next;
	}
	l_lstptonull(alist);
}
