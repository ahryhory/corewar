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

# define COUNT_OP 16

typedef struct				s_optab
{
	char					name[10];
	int						args_number;
	int						args[3][3];
	char					opcode[5];
	int						cycles;
	char					description[50];
	int						carry;
	int						cod_octal;
	int						lable_size;
}							t_optab;

t_optab						g_optab[COUNT_OP];

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

typedef struct 				s_args
{
	int						op;
	t_commands 				*cmd;
	int 					fd;
	int						*oct;
	int						*line;
}							t_args;

t_data						parse(char *file);
void						write_exec(t_args args, t_commands *cur, t_commands *cmd);
void						parse_line(char *line, t_commands **command);
void						write_byte(t_data data, char *file);
void						write_header(int fd, t_data data, int *oct, int *line);
void						cpy_in_4b(int nbr, char w[10]);
void						cpy_in_2b(int nbr, char w[5]);
void						cpy_in_1b(int nbr, char w[3]);
void						write_1b(int fd, int *oct, int *line, char w[3]);
void						write_4b(int fd, int *oct, int *line, char w[10]);
void						write_2b(int fd, int *oct, int *line, char w[5]);
int							count_al(int fd, int *oct, int *line);
void						check_line(char **line, int number_line);
void						check_comment(char *line);
int							check_quotes(char *line);
void						check_start_line(char **line);
void						check_other_line(char **line);
int							check_cmd(char *line);
void						ft_exit(int error);
void						init_name(void);
void						init_args_number(void);
void						init_args(void);
void						init_opcode(void);
void						init_cycles(void);
void						init_description(void);
void						init_carry(void);
void						init_cod_octal(void);
void						init_lable_size(void);

#endif
