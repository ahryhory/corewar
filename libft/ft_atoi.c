/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:27:41 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/04 16:19:56 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	unsigned long long	num;
	short				neg;

	num = 0;
	neg = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str && '0' <= *str && *str <= '9')
		num = num * 10 + (*str++ - '0');
	if (num > 9223372036854775807 && neg == -1)
		return (0);
	if (num > 9223372036854775807)
		return (-1);
	return ((int)(num * neg));
}
