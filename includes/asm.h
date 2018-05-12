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
# include <fcntl.h>
# include <stdio.h>

#define	C_BUFF				"**** **** **** **** **** **** **** ****\n"

typedef struct				s_optab
{
	char					*name;
	int						args_number;
	int						args[3][3];
	int						opcode;
	int						cycles;
	char					*description;
	int						carry;
	int						cod_octal;
	int						lable_size;
}							t_optab;

typedef struct 				s_commands
{
	char					*label;
	char					*command;
	char					*arg_1;
	char					*arg_2;
	char					*arg_3;
	int						begin;
	int						size;
	struct s_commands		*next;
}							t_commands;

typedef struct 				s_data
{
	t_commands				*command;
	t_header				head;
}							t_data;

char						g_buff[41];

t_data						parse(char *file);
void						write_byte(t_data data, char *file);
void						write_header(int fd, t_data data);

#endif
