# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 16:37:19 by iseletsk          #+#    #+#              #
#    Updated: 2018/05/04 16:22:48 by iseletsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC := ft_count_c.c ft_atoi.c ft_bzero.c ft_coundig.c ft_count_word.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstdup.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_revers.c ft_skip_whtsp.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c get_next_line.c ft_abs.c ft_read_output.c ft_strjoin_md.c

all: $(NAME)

$(NAME):
	make -C ./ft_printf
	gcc -c -Wall -Werror -Wextra $(SRC) -I ./includes/
	ar rc $(NAME) $(SRC:.c=.o) ./ft_printf/*.o

clean:
	make clean -C ./ft_printf
	rm -f $(SRC:.c=.o)

fclean: clean
	make fclean -C ./ft_printf
	rm -f $(NAME)

re: fclean all
