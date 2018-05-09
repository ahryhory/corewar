/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:21:28 by ahryhory          #+#    #+#             */
/*   Updated: 2017/10/30 16:36:17 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create(long int nm, long int div, size_t size)
{
	int			i;
	char		*nstr;

	i = 0;
	if (nm < 0)
	{
		nm *= -1;
		nstr = ft_strnew(size + 1);
		if (nstr == NULL)
			return (NULL);
		nstr[i++] = '-';
	}
	else
		nstr = ft_strnew(size);
	if (nstr == NULL)
		return (NULL);
	while (size--)
	{
		div /= 10;
		nstr[i++] = (char)(nm / div + '0');
		nm %= div;
	}
	return (nstr);
}

char		*ft_itoa(int n)
{
	long int	div;
	long int	nm;
	char		*nstr;
	size_t		size;

	size = 1;
	div = 10;
	nm = (long int)n;
	while (nm / div != 0)
	{
		div *= 10;
		size++;
	}
	nstr = ft_create(nm, div, size);
	return (nstr);
}
