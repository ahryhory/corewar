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
# define FLAG_A "-a"

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

typedef struct 				s_info
{
	char					**line;
	int						num;
	int						real_num;
}							t_info;

typedef struct 				s_data
{
	t_commands				*command;
	t_header				head;
}							t_data;

t_data						parse(char *file, t_info info);
void						parse_line(char *line, t_commands **command);
void						write_byte(t_data data, char *file);
void						write_header(int fd, t_data data, int *oct, int *line);
void						cpy_in_4b(t_data data, char w[10]);
void						check_line(t_info info);
void						check_comment(char *line, t_info info);
int							check_quotes(char *line, t_info info);
void						check_start_line(t_info info);
void						check_other_line(t_info info);
int							check_cmd(char *line, t_info info);
int							check_first_patr(char **line, t_info info);
void						ft_exit(int error, t_info info);
void						init_name(void);
void						init_args_number(void);
void						init_args(void);
void						init_opcode(void);
void						init_cycles(void);
void						init_description(void);
void						init_carry(void);
void						init_cod_octal(void);
void						init_lable_size(void);
void						flag_a(t_data *data);
t_commands					*init_command(void);
int							get_label_size(char *command);
char						*create_codage(t_commands *curr);
void						check_args(char **line, int command, t_info info);
int							check_arg(char *arg, int command, int arg_num);
void						check_commands(t_commands *commands);

#endif
