/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:38:14 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/22 15:08:10 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	countwords;

	countwords = 0;
	i = 0;
	if (s[0] != c && s[0] != '\0')
		countwords++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			countwords++;
		i++;
	}
	return (countwords + 1);
}

static int	ft_countchar(char const *s, char c, int i)
{
	int	countchar;

	countchar = 0;
	while (s[i] != c && s[i])
	{
		countchar++;
		i++;
	}
	return (countchar);
}

static char	**ft_free(char ***words)
{
	while (**words)
		ft_strdel(*words++);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**words;
	int		j;
	int		countchar;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	words = (char **)ft_memalloc(sizeof(char *) * ft_countwords(s, c));
	if (words == NULL)
		return (NULL);
	while (s[i])
	{
		countchar = ft_countchar(s, c, i);
		if (countchar > 0)
		{
			if ((words[j++] = ft_strsub(s, i, countchar)) == NULL)
				return (ft_free(&words));
			i += countchar - 1;
		}
		i++;
	}
	words[j] = 0;
	return (words);
}
