# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/20 16:19:53 by ybohusev          #+#    #+#              #
#    Updated: 2018/06/03 16:55:11 by ahryhory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, get_lib

NAME_A = asm
NAME_C = corewar

C = gcc

FLAGS += -Wall -Wextra -Werror

LIBFT = ./libft/
LIB = ./libft/libft.a
ASM_SRC = asm_src
ASM_OBJ = asm_obj
COR_SRC = vm_src
COR_OBJ = vm_obj
INC = ./includes

SRC_A = 

SRC_A += asm.c
SRC_A += parse.c
SRC_A += parse_line.c
SRC_A += write_byte.c
SRC_A += write_header.c
SRC_A += stuff_funcs.c
SRC_A += check_line.c
SRC_A += check_other_line.c
SRC_A += check_cmd.c
SRC_A += check_comment.c
SRC_A += check_quotes.c
SRC_A += check_start_line.c
SRC_A += ft_exit.c
SRC_A += init_args_number.c
SRC_A += init_args.c
SRC_A += init_opcode.c
SRC_A += init_cycles.c
SRC_A += init_description.c
SRC_A += init_carry.c
SRC_A += init_cod_octal.c
SRC_A += init_lable_size.c
SRC_A += init_name.c
SRC_A += write_exec.c
SRC_A += check_first_patr.c
SRC_A += init_command.c
SRC_A += get_label_size.c
SRC_A += create_codage.c
SRC_A += check_args.c
SRC_A += check_arg.c
SRC_A += flag_a.c
SRC_A += check_commands.c
SRC_A += modif_line.c
SRC_A += add_new_to_list.c
SRC_A += pl_func.c
SRC_A += re_read.c
SRC_A += parse_func.c
ASM_SRCS = $(addprefix $(ASM_SRC)/,$(SRC_A))
ASM_OBJS = $(addprefix $(ASM_OBJ)/,$(SRC_A:.c=.o))

SRC_C = 

SRC_C += vm_valid_nbr.c
SRC_C += vm_start_proc_init.c
SRC_C += vm_hendl_nbr_ch.c
SRC_C += vm_give_fbyte.c
SRC_C += usage_vm.c
SRC_C += vm_salution.c
SRC_C += vm_init_flag.c
SRC_C += vm_give_winer.c
SRC_C += vm.c
SRC_C += allocate_memory.c
SRC_C += add_champions.c
SRC_C += do_add.c
SRC_C += do_aff.c
SRC_C += do_and.c
SRC_C += do_fork.c
SRC_C += do_ld.c
SRC_C += do_ldi.c
SRC_C += do_lfork.c
SRC_C += do_live.c
SRC_C += do_lld.c
SRC_C += do_lldi.c
SRC_C += do_or.c
SRC_C += do_st.c
SRC_C += do_sti.c
SRC_C += do_sub.c
SRC_C += do_xor.c
SRC_C += do_zjmp.c
SRC_C += init_args_number.c
SRC_C += init_args.c
SRC_C += init_opcode.c
SRC_C += init_cycles.c
SRC_C += init_description.c
SRC_C += init_carry.c
SRC_C += init_cod_octal.c
SRC_C += init_lable_size.c
SRC_C += init_name.c
SRC_C += get_index.c
SRC_C += get_nbr.c
SRC_C += vm_del_proc.c
SRC_C += vm_give_codg.c
SRC_C += vm_hendl_byte.c
SRC_C += vm_hendl_proc.c
SRC_C += vm_hendl_command.c
SRC_C += vm_add_chemp.c
SRC_C += vm_add_proces.c
SRC_C += vm_show_map_win.c
SRC_C += vm_count_proc.c
SRC_C += vm_check_proc.c
SRC_C += init_ncurses.c
SRC_C += draw_info.c
SRC_C += draw_color.c
SRC_C += write_dump.c
SRC_C += flip_bytes.c
SRC_C += start_ncurs.c
SRC_C += general_cycle.c
SRC_C += sginls.c
SRC_C += if_v.c
SRC_C += usage_info.c
SRC_C += vm_validation.c

COR_SRCS = $(addprefix $(COR_SRC)/,$(SRC_C))
COR_OBJS = $(addprefix $(COR_OBJ)/,$(SRC_C:.c=.o))

all: get_lib $(NAME_A) $(NAME_C)

get_lib:
	@make -C $(LIBFT)

$(NAME_A): $(ASM_OBJS)
	@$(C) $(FLAGS) -o $(NAME_A) $(ASM_OBJS) $(LIB) -I $(LIBFT) -I $(INC)

$(NAME_C): $(COR_OBJS)
	@$(C) $(FLAGS) -o $(NAME_C) $(COR_OBJS) $(LIB) -I $(LIBFT) -I $(INC) -lncurses

$(ASM_OBJ)/%.o: $(ASM_SRC)/%.c
	@mkdir -p $(ASM_OBJ)
	@$(C) $(FLAGS) -c -I $(LIBFT) -I $(INC) -o $@ -c $<

$(COR_OBJ)/%.o: $(COR_SRC)/%.c
	@mkdir -p $(COR_OBJ)
	@$(C) $(FLAGS) -c -I $(LIBFT) -I $(INC) -o $@ -c $<

clean:
	@rm -rf $(ASM_OBJ)
	@rm -rf $(COR_OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME_A)
	@rm -f $(NAME_C)
	@make fclean -C $(LIBFT)

re: fclean all
