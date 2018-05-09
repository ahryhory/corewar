/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:55:39 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/04 15:57:18 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;
	t_list	*next;

	elem = *alst;
	while (elem != NULL)
	{
		next = elem->next;
		ft_lstdelone(&elem, del);
		elem = next;
	}
	*alst = NULL;
}
