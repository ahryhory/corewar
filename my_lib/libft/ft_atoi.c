/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:56:04 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/02 16:25:26 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	long long int	sign;
	long long int	result;

	result = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
		result = result * 10 + (*str++ - '0');
	if (sign == 1 && result > 2147483647)
		return (-1);
	else if (sign == -1 && result > 2147483648)
		return (0);
	return (sign * result);
}
