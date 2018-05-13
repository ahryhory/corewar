# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/20 16:19:53 by ybohusev          #+#    #+#              #
#    Updated: 2018/04/20 16:19:54 by ybohusev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, get_lib

NAME_A = asm

C = gcc

# FLAGS += -Wall -Wextra -Werror

LIBFT = ./libft/
LIB = ./libft/libft.a
ASM_SRC = asm_src
ASM_OBJ = asm_obj
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
SRC_A += check_first_patr.c
SRC_A += init_command.c
SRC_A += get_label_size.c
SRC_A += create_codage.c
SRC_A += check_args.c

ASM_SRCS = $(addprefix $(ASM_SRC)/,$(SRC_A))
ASM_OBJS = $(addprefix $(ASM_OBJ)/,$(SRC_A:.c=.o))

all: get_lib $(NAME_A)

get_lib:
	@make -C $(LIBFT)

$(NAME_A): $(ASM_OBJS)
	@$(C) $(FLAGS) -o $(NAME_A) $(ASM_OBJS) $(LIB) -I $(LIBFT) -I $(INC)

$(ASM_OBJ)/%.o: $(ASM_SRC)/%.c
	@mkdir -p $(ASM_OBJ)
	@$(C) $(FLAGS) -c -I $(LIBFT) -I $(INC) -o $@ -c $<

clean:
	@rm -rf $(ASM_OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME_A)
	@make fclean -C $(LIBFT)

re: fclean all
