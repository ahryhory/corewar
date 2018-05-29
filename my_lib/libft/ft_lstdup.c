/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:31:19 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/27 15:11:34 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*rlist;
	t_list	*blist;
	t_list	*bblist;

	blist = 0;
	while (lst)
	{
		if (!(rlist = ft_lstnew(lst->content, lst->content_size)))
			return (0);
		if (!blist)
		{
			blist = rlist;
			bblist = blist;
		}
		else
		{
			blist->next = rlist;
			blist = blist->next;
		}
		rlist = rlist->next;
		lst = lst->next;
	}
	return (bblist);
}
