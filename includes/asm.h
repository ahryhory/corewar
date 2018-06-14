/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 11:12:56 by ybohusev          #+#    #+#             */
/*   Updated: 2018/06/02 16:27:10 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>

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

typedef struct				s_commands
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

typedef struct				s_parse
{
	int						fd;
	int						count;
	int						real_count;
	int						gnl;
	char					*line;
}							t_parse;

typedef struct				s_info
{
	char					**line;
	int						num;
	int						real_num;
}							t_info;

typedef struct				s_data
{
	t_commands				*command;
	t_header				head;
}							t_data;

typedef struct				s_args
{
	int						op;
	t_commands				*cmd;
	int						fd;
	int						*oct;
	int						*line;
}							t_args;

void						write_exec(t_args args, t_commands *cur,
										t_commands *cmd);
t_data						parse(char *file, t_info info);
void						parse_line(char *line, t_commands **command);
void						write_byte(t_data data, char *file);
void						write_header(int fd, t_data data, int *oct,
										int *line);
void						write_1b(int fd, unsigned char size);
void						write_4b(int fd, unsigned int size);
void						write_2b(int fd, unsigned short size);
void						check_line(t_info info);
void						check_comment(char *line, t_info info);
int							check_quotes(char *line, t_info info, int comment);
void						check_start_line(t_info info);
void						check_other_line(t_info info);
int							check_cmd(char *line, t_info info, int *comment);
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
unsigned char				create_codage(t_commands *cmd);
void						check_args(char **line, int command, t_info info);
int							check_arg(char *arg, int command, int arg_num);
void						check_commands(t_commands *commands);
void						modif_line(char **p_line);
void						add_new_to_list(t_commands **command,
										t_commands *new);
void						get_command(t_commands **new, char *line,
										char **trim);
char						*add_command(t_commands **new, char *line);
void						if_cmd_line(char **line, int fd, t_info info,
										char *define_cmd_string);
int							if_label(char **join, t_parse *parse,
										t_data *data, char **trim);
void						read_while_not_command(t_parse *parse,
										t_data *data, char **trim);
void						if_command(t_parse *parse, t_data *data);
void						init_and_check(t_data *data, t_info *info,
										t_parse *parse, char *file);
int							is_all_quotes(char *begin, char *line);
int							processing(char **line, int real_count, int count,
										t_data *data);
void						add_size(t_data *data);
char						*get_content_in_quotation(char *line);

#endif
