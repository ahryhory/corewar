/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:19:41 by ahryhory          #+#    #+#             */
/*   Updated: 2018/05/10 12:19:42 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_start_line(char *line, int number_line)
{
	
}

int			check_line(char *line, int number_line)
{
	int		error;

	error = 0;
	if (number_line == 0 || number_line == 1)
	{
		if ((error = check_start_line(line)) != 0)
			return (error);
	}
	else
	{

	}
}
