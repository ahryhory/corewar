/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:12:56 by ybohusev          #+#    #+#             */
/*   Updated: 2018/05/10 11:12:57 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft.h"
# include <stdio.h>

typedef struct				s_optab
{
	char					*name;
	int						opcode;
	int						args_number;
	int						args[3];
	int						lable_size;
}							t_optab;

typedef struct 				s_commands
{
	char					*lable;
	char					*command;
	int						begin;
	int						size;
	struct s_data			*next;
}							t_commands;

typedef struct 				s_data
{
	t_commands				*command;
	char					*name;
	char					*comment;
}							t_data;

#endif
