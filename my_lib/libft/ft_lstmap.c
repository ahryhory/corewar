/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:21:36 by iseletsk          #+#    #+#             */
/*   Updated: 2018/03/24 19:28:39 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*rlist;
	t_list	*blist;
	t_list	*slist;
	t_list	*bblist;

	blist = 0;
	while (lst)
	{
		slist = f(lst);
		if (!(rlist = ft_lstnew(slist->content, slist->content_size)))
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
